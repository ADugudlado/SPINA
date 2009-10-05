////////////////////////////////////////////////////////////////////////
// InterpreterVisitor.cpp: Implements a vistor that interprets the 
//  syntax tree.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "InterpreterVisitor.h"
#include <iostream>
#include <sstream> 
#include<vector>

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
    int result = rhs + lhs;
    mStack.push(result);    
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
		for(int i=0;i<rhs.size();i++){
			std::vector<int> row;
			for(int j=0;j<rhs.begin()->size();j++){
				row.push_back( rhs[i][j]+lhs[i][j]);
			}
			result.push_back(row);
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
    /*int rhs = getTopOfStack();
    int lhs = getTopOfStack();
    int result = rhs + lhs;
    mStack.push(result);    */
}