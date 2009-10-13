#ifndef PRETTY_PRINT_VISITOR_H
#define PRETTY_PRINT_VISITOR_H
////////////////////////////////////////////////////////////////////////
// PrettyPrintVisitor.h: demonstrates printing the syntax tree in 
//  a difference source language than the input for the Interp language.
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


using namespace System;

public class PrettyPrintVisitor : public Visitor {
public:
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

#endif PRETTY_PRINT_VISITOR_H