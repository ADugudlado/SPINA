////////////////////////////////////////////////////////////////////////
// InterpreterVisitor.cpp: Implements a vistor that interprets the 
//  syntax tree.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "InterpreterVisitor.h"
#include <iostream>
#include <sstream> 
#include <string>
#include<vector>
#include "ThreadClasses.h"
InterpreterVisitor::InterpreterVisitor(){
}

bool InterpreterVisitor::map_contains_key(std::string key){
   std::map<std::string,int>::iterator it;
   it = mVariableMap.find(key);   
   if(it == mVariableMap.end())
      return false;
   return true;
}
bool InterpreterVisitor::map_contains_matrixkey(std::string key){
   std::map<std::string,std::vector<std::vector<int>>>::iterator mit;	
   mit = mMatrixMap.find(key);
   if(mit == mMatrixMap.end())
      return false;
   return true;
}


void InterpreterVisitor::VisitVariableElement(VariableElement * element){
    if(map_contains_key(element->getText())){
      int element_value = (int) mVariableMap[element->getText()];
      mStack.push(element_value);
    } else {
      //lets assume that the syntax has been checked for this example because I don't like the exception
      //propegation that will happen if I throw here
      //throw new Exception("Variable " + element.getText() + " not defined.");
    }
}

void InterpreterVisitor::VisitMatrixVariableElement(MatrixVariableElement * element){
    if(map_contains_matrixkey(element->getText())){
      std::vector<std::vector<int>> element_value =  mMatrixMap[element->getText()];
      matrixStack.push(element_value);
    } else {
      //lets assume that the syntax has been checked for this example because I don't like the exception
      //propegation that will happen if I throw here
      //throw new Exception("Variable " + element.getText() + " not defined.");
    }
}

void InterpreterVisitor::VisitMatrixValueElement(MatrixValueElement * element){
	std::vector<std::vector<int>> temp=element->getMatrix();
	matrixStack.push(temp);
}


int InterpreterVisitor::parseInt(std::string value){
   std::istringstream iss(value);
   int ret;
   iss >> ret;
   return ret;
}

void InterpreterVisitor::VisitIntegerElement(IntegerElement * element){
    int element_value = parseInt(element->getText());
    mStack.push(element_value);
}
  
int InterpreterVisitor::getTopOfStack(){
   int result=-1;
   if(mStack.size()>0){
	   result = mStack.top();
		mStack.pop();
   }
   return result;
}
std::vector<std::vector<int>> InterpreterVisitor::getTopOfMatrixStack(){
   std::vector<std::vector<int>> result;
   if(matrixStack.size()>0){
	   result =  matrixStack.top();
		matrixStack.pop();
   }
   return result;
}

void InterpreterVisitor::VisitAssignmentOperationElement(AssignmentOperationElement * element){
    std::string variable_name = element->getLhs()->getText();
    Element * rhs = element->getRhs();
    VisitElement(rhs);
    int result = getTopOfStack();
    mVariableMap[variable_name] = result;
}
void InterpreterVisitor::VisitMatrixAssignmentOperationElement(MatrixAssignmentOperationElement * element){
    std::string variable_name = element->getLhs()->getText();
	Element * rhs = element->getRhs();
    VisitElement(rhs);
	std::vector<std::vector<int>> result = getTopOfMatrixStack();
	if(result.size()!=0)
		mMatrixMap[variable_name] = result;
}

void InterpreterVisitor::VisitAdditionOperationElement(AdditionOperationElement * element){
    VisitElement(element->getLhs());
    VisitElement(element->getRhs());
    int rhs = getTopOfStack();
    int lhs = getTopOfStack();
	if(rhs!=-1&&lhs!=-1){
     int result = rhs + lhs;
     mStack.push(result);
	}else{
		std::cout<<"\nOne of the Variables doesn't exist";		
		std::cout<<"\nAborting Addition Operation";
		return;
	}
}

void InterpreterVisitor::VisitMultiplyOperationElement(MultiplyOperationElement * element){
    VisitElement(element->getLhs());
    VisitElement(element->getRhs());
    int rhs = getTopOfStack();
    int lhs = getTopOfStack();
    int result = rhs * lhs;
    mStack.push(result);    
}

void InterpreterVisitor::VisitPrintOperationElement(PrintOperationElement * element){
    VisitElement(element->getChildElement());
    int result = getTopOfStack();
	if(result!=-1)
      std::cout << result << std::endl;
	else
		std::cout<<"\nVariable doesn't exist\n";
}
void InterpreterVisitor::VisitMatrixPrintOperationElement(MatrixPrintOperationElement *element){
	VisitElement(element->getChildElement());
    std::vector<std::vector<int>> printmatrix = getTopOfMatrixStack();
	if(printmatrix.size()!=0){
		std::cout << "matrix values:" ;
		std::cout<<"\n";
		for(unsigned i=0;i<printmatrix.size();i++){
			for(unsigned j=0;j<printmatrix[i].size();j++){
				std::cout<<printmatrix[i][j]<<" ";
			}
			std::cout<<"\n";
		}
	}
	else
		std::cout<<"\nMatrix Variable doesn't exist\n";
}

void InterpreterVisitor::VisitMatrixAdditionOperationElement(MatrixAdditionOperationElement * element){
    VisitElement(element->getLhs());
    VisitElement(element->getRhs());
	std::vector<std::vector<int>> rhs = getTopOfMatrixStack();
    std::vector<std::vector<int>> lhs = getTopOfMatrixStack();
    std::vector<std::vector<int>> result ;
	if(rhs.size()==lhs.size()&&rhs.begin()->size()==lhs.begin()->size()){
		std::vector<AddThread*> process;
		AddThread *tempProcess;
		thread *t;
		std::vector<thread*> ts;
		for(unsigned i=0;i<rhs.size();i++){			
			tempProcess=new AddThread(std::string("Thread "));
			tempProcess->updateThread(rhs[i],lhs[i]);
			process.push_back(tempProcess);
			t=new thread(*tempProcess);
			t->start();
			ts.push_back(t);
		}
		for(unsigned i=0;i<ts.size();){
			WaitForSingleObject(ts[i]->handle(),INFINITE);
			i++;
		}
		for(unsigned i=0;i<process.size();i++){
			result.push_back(process[i]->returnSum());
		}
	}else{
		std::cout<<"\nMismatch of Orders of given Matrices";
		return;
	}
    matrixStack.push(result);    
}
          
void InterpreterVisitor::VisitMatrixMultiplyOperationElement(MatrixMultiplyOperationElement * element){
    VisitElement(element->getLhs());
    VisitElement(element->getRhs());
    std::vector<std::vector<int>> rhs = getTopOfMatrixStack();
    std::vector<std::vector<int>> lhs = getTopOfMatrixStack();
	std::vector<std::vector<int>> tempMatrix=matrixTanspose(rhs);
    std::vector<std::vector<int>> result ;
	if(lhs.begin()->size()==rhs.size()){
		std::vector<std::vector<MultiplyThread*>> processlist;
		std::vector<MultiplyThread*> process;
		MultiplyThread *tempProcess;
		std::vector<thread*> ts;
		thread *t;
		for(unsigned i=0;i<lhs.size();i++){			
			for(unsigned j=0;j<tempMatrix.size();j++){
				tempProcess=new MultiplyThread(std::string("Thread "));
				tempProcess->updateThread(lhs[i],tempMatrix[j]);
				process.push_back(tempProcess);
				t=new thread(*tempProcess);
				t->start();
				ts.push_back(t);
			}
			processlist.push_back(process);
			process.clear();
		}
		for(unsigned i=0;i<ts.size();){
			WaitForSingleObject(ts[i]->handle(),INFINITE);
			i++;
		}
		for(unsigned i=0;i<processlist.size();i++){			
		  std::vector<int> row;
		  for(unsigned j=0;j<processlist[i].size();j++){			
			row.push_back(processlist[i][j]->returnProduct());
		  }
		  result.push_back(row);
		}
	
	}else{
		std::cout<<"\nNumber of Columns of first Matrix and Rows of second Matrix are not equal";
		return;
	}
	matrixStack.push(result);    
}

std::vector<std::vector<int>> InterpreterVisitor::matrixTanspose(std::vector<std::vector<int>> mat){
	std::vector<std::vector<int>> matrixTp;
	for(unsigned i=0;i<mat.begin()->size();i++){
		std::vector<int> temp;
		for(unsigned j=0;j<mat.size();j++){
			temp.push_back(mat[j][i]);
		}
		matrixTp.push_back(temp);
	}
	return matrixTp;
}

void InterpreterVisitor::VisitParallelforOperationElement(ParallelforOperationElement *element){
	    vector<AssignmentOperationElement *> assignlist=element->getBody();
		//int thCount = element->getEndValue()-element->getEndValue();
		HANDLE createTh;
		vector<HANDLE *> thlist ;
		DWORD tid;
		ParallelforThread *temp=new ParallelforThread();
		temp->setInterpreterVisitor(this);
		temp->setElement(element);
		mVariableMap[element->getIndexVariableName()]=element->getStartValue();
		for(unsigned i=element->getStartValue();i<element->getEndValue();i++){
			mVariableMap[element->getIndexVariableName()]=i;
			temp->setCurrentValue(i);
		    createTh=CreateThread(NULL,0,startIteration,temp,0,&tid);
			thlist.push_back( &createTh);
		}
		for(unsigned i=0;i<thlist.size();i++)
			WaitForSingleObject(thlist[i],INFINITE);
		
}

