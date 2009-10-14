#ifndef THREAD_CLASSES_H
#define THREAD_CLASSES_H

//////////////////////////////////////////////////////////////////////// 
// ThreadClasses.h: It contains classes which perform certain operations
// like Add,Multiply and useful in making threads in matrix operations.
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "AssignmentOperationElement.h"
#include "ParallelforOperationElement.h"
#include "InterpreterVisitor.h"
#include "Threads.h"
#include "locks.h"
#include<string>
#include<vector>


class AddThread : public Thread_Processing
{
public:
  AddThread* clone() const
  {
    return new AddThread(*this);   // applications must have this line, e.g.,
                                  // clone creating a copy of self
  }
  ~AddThread() { }
  AddThread(const AddThread& tp) 
  {
	  row1=tp.row1;
	  row2=tp.row2;
	  sum=tp.sum;
	  _str=tp._str;
    sout << locker << "\n  " << _str << unlocker;
  }
  AddThread(const std::string& str) 
  {
    sout << locker << "\n  " << _str << unlocker;
  }
  std::vector<int> returnSum(){
	  return sum;
  }
  void updateThread(std::vector<int> a,std::vector<int> b){
	 row1=a;
	 row2=b;
  }
  virtual void run()
  {
	  for(unsigned i=0;i<row1.size();i++){
		sum.push_back(row1[i]+row2[i]);			
	  }
  }
  
private:
  std::string _str;
  std::vector<int> row1,row2;
  int rowlength;
  std::vector<int> sum;
};

class MultiplyThread : public Thread_Processing
{
public:
  MultiplyThread* clone() const
  {
    return new MultiplyThread(*this);   // applications must have this line, e.g.,
                                  // clone creating a copy of self
  }
  ~MultiplyThread() { }
  MultiplyThread(const MultiplyThread& tp) 
  {
	  row=tp.row;
	  col=tp.col;
	  product=tp.product;
	  _str=tp._str;
    sout << locker << "\n  " << _str << unlocker;
  }
  MultiplyThread(const std::string& str) 
  {
    sout << locker << "\n  " << _str << unlocker;
  }
  int returnProduct(){
	  return product;
  }
  void updateThread(std::vector<int> a,std::vector<int> b){
	 row=a;
	 col=b;
  }
  virtual void run()
  {
	  product=0;
	  for(unsigned i=0;i<row.size();i++){
		 product+=row[i]*col[i];
	  }
  }
  
private:
  std::string _str;
  std::vector<int> row,col;
  int rowlength;
  int product;
};

class ParallelforThread{
public:
	ParallelforOperationElement* getElement(){return elem;}
	void setElement(ParallelforOperationElement* el){elem=el;}
	InterpreterVisitor* getInterpreterVisitor(){return interp;}
	void setInterpreterVisitor(InterpreterVisitor* i){interp=i;}
	int getCurrentValue(){return current;}
	void setCurrentValue(int c){current=c;}
private:ParallelforOperationElement*  elem;
		InterpreterVisitor* interp;
		int current;
};

DWORD WINAPI startIteration(LPVOID lpParam){
	    ParallelforThread *temp=(ParallelforThread*)lpParam; 
		ParallelforOperationElement*  tempelem=temp->getElement();
		InterpreterVisitor* tempInterp=temp->getInterpreterVisitor();
		std::map<std::string, int> tempMap=tempInterp->getMap();
		vector<AssignmentOperationElement*> assignlist=tempelem->getBody();
		tempMap[tempelem->getIndexVariableName()]=temp->getCurrentValue();
		for(unsigned j=0;j<assignlist.size();j++){
	       tempInterp->VisitAssignmentOperationElement(assignlist[j]);
		}
		return 0;
}

#endif //THREAD_CLASSES_H
