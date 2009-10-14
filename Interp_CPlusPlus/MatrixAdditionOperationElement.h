#ifndef MATRIX_ADDITION_OPERATION_ELEMENT_H
#define MATRIX_ADDITION_OPERATION_ELEMENT_H
////////////////////////////////////////////////////////////////////////
// MatrixAdditionOperationElement.h: holds the data needed for an addition 
//  operation on Matrices.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////

#include "Element.h"

public class MatrixAdditionOperationElement : public Element {
private:
  Element * mLhs;
  Element * mRhs;  
public:
  virtual void Accept(Visitor * visitor);

  Element * getLhs();
  void setLhs(Element * lhs);

  Element * getRhs();
  void setRhs(Element * rhs);
};
#endif //MATRIX_ADDITION_OPERATION_ELEMENT_H