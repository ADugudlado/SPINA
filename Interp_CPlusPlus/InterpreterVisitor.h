#ifndef INTERPRETER_VISITOR_H
#define INTERPRETER_VISITOR_H
////////////////////////////////////////////////////////////////////////
// InterpreterVisitor.h: Implements a vistor that interprets the 
//  syntax tree.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "Visitor.h"
#include "VariableElement.h"
#include "MatrixVariableElement.h"
#include "MatrixValueElement.h"
#include "MatrixAssignmentOperationElement.h"
#include "MatrixPrintOperationElement.h"
#include "MatrixAdditionOperationElement.h"
#include "MatrixMultiplyOperationElement.h"
#include "IntegerElement.h"
#include "AssignmentOperationElement.h"
#include "AdditionOperationElement.h"
#include "PrintOperationElement.h"
#include "MultiplyOperationElement.h"
#include "ParallelforOperationElement.h"
#include <map>
#include <stack>
#include <string>

public class InterpreterVisitor : public Visitor {
private:
   std::map<std::string, int> mVariableMap;
   std::map<std::string,std::vector<std::vector<int>>> mMatrixMap;
   std::stack<int> mStack;
   std::stack<std::vector<std::vector<int>>> matrixStack;
   bool map_contains_key(std::string key);
   bool map_contains_matrixkey(std::string);
   int parseInt(std::string value);
   int getTopOfStack();
   std::vector<std::vector<int>> getTopOfMatrixStack();
   std::vector<std::vector<int>> matrixTanspose(std::vector<std::vector<int>>);
public:
  InterpreterVisitor();
  virtual void VisitVariableElement(VariableElement * element);
  virtual void VisitMatrixVariableElement(MatrixVariableElement * element);
  virtual void VisitMatrixValueElement(MatrixValueElement * element);
  virtual void VisitMatrixAssignmentOperationElement(MatrixAssignmentOperationElement * element);
  virtual void VisitMatrixPrintOperationElement(MatrixPrintOperationElement * element);
  virtual void VisitMatrixMultiplyOperationElement(MatrixMultiplyOperationElement * element);
  virtual void VisitMatrixAdditionOperationElement(MatrixAdditionOperationElement * element);
  virtual void VisitIntegerElement(IntegerElement * element);
  virtual void VisitAssignmentOperationElement(AssignmentOperationElement * element);
  virtual void VisitAdditionOperationElement(AdditionOperationElement * element);
  virtual void VisitPrintOperationElement(PrintOperationElement * element);
  virtual void VisitMultiplyOperationElement(MultiplyOperationElement * element);
  virtual void VisitParallelforOperationElement(ParallelforOperationElement * element);
};

#endif //INTERPRETER_VISITOR_H