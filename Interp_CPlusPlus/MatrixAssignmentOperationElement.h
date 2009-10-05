#ifndef MATRIX_ASSIGNMENT_OPERATION_ELEMENT_H
#define MATRIX_ASSIGNMENT_OPERATION_ELEMENT_H

////////////////////////////////////////////////////////////////////////
// MatrixAssignmentOperationElement.h: holds the data needed for an 
//  assignment operation.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "Element.h"
#include "MatrixVariableElement.h"
#include "Visitor.h"

public class MatrixAssignmentOperationElement : public Element {
private:
  MatrixVariableElement * mLhs;
  Element * mRhs;  
public:
  virtual void Accept(Visitor * visitor);

  MatrixVariableElement * getLhs();
  void setLhs(MatrixVariableElement * lhs);

  Element * getRhs();
  void setRhs(Element * rhs);
};

#endif //MATRIX_ASSIGNMENT_OPERATION_ELEMENT_H