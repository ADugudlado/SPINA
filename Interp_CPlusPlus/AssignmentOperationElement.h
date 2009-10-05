#ifndef ASSIGNMENT_OPERATION_ELEMENT_H
#define ASSIGNMENT_OPERATION_ELEMENT_H

////////////////////////////////////////////////////////////////////////
// AssignmentOperationElement.h: holds the data needed for an 
//  assignment operation.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "Element.h"
#include "VariableElement.h"
#include "Visitor.h"

public class AssignmentOperationElement : public Element {
private:
  VariableElement * mLhs;
  MatrixVariableElement * matrixmLhs;
  Element * mRhs;  
public:
  virtual void Accept(Visitor * visitor);

  MatrixVariableElement * getMatrixLhs();
  VariableElement * getLhs();
  void setLhs(VariableElement * lhs);
  void setMatrixLhs(MatrixVariableElement * lhs);

  Element * getRhs();
  void setRhs(Element * rhs);
};

#endif //ASSIGNMENT_OPERATION_ELEMENT_H