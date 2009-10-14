#ifndef VISITOR_H
#define VISITOR_H

////////////////////////////////////////////////////////////////////////
// Visitor.h: declares all the abstract Visit functions that each
//  visitor must implement.  Also includes the VisitElement function
//  which alows visiting of an Element when its type is not known.
// 
// version: 1.1
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////

class VariableElement;
class MatrixVariableElement;
class MatrixValueElement;
class MatrixAssignmentOperationElement;
class MatrixAdditionOperationElement;
class MatrixMultiplyOperationElement;
class IntegerElement;
class AssignmentOperationElement;
class AdditionOperationElement;
class PrintOperationElement;
class MatrixPrintOperationElement;
class MultiplyOperationElement;
class  ParallelforOperationElement;
class Element;

public class Visitor {

public:
  virtual void VisitVariableElement(VariableElement * element) = 0;
  virtual void VisitMatrixVariableElement(MatrixVariableElement * element) = 0;
  virtual void VisitMatrixValueElement(MatrixValueElement * element) = 0; 
  virtual void VisitMatrixAssignmentOperationElement(MatrixAssignmentOperationElement * element) = 0;
  virtual void VisitMatrixAdditionOperationElement(MatrixAdditionOperationElement * element) = 0;
  virtual void VisitMatrixMultiplyOperationElement(MatrixMultiplyOperationElement * element) = 0;
  virtual void VisitMatrixPrintOperationElement(MatrixPrintOperationElement * element) = 0;
  virtual void VisitIntegerElement(IntegerElement * element) = 0;
  virtual void VisitAssignmentOperationElement(AssignmentOperationElement * element) = 0;
  virtual void VisitAdditionOperationElement(AdditionOperationElement * element) = 0;
  virtual void VisitPrintOperationElement(PrintOperationElement * element) = 0;
  virtual void VisitMultiplyOperationElement(MultiplyOperationElement * element) = 0;
  virtual void VisitParallelforOperationElement(ParallelforOperationElement * element)=0;

  void VisitElement(Element * element);

protected:
  Visitor() { }
};

#endif //VISITOR_H