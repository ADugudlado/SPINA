#ifndef MULTIPLY_OPERATION_ELEMENT_H
#define MULTIPLY_OPERATION_ELEMENT_H
////////////////////////////////////////////////////////////////////////
// MultiplyOperationElement.h: holds the data needed for an Multiply 
//  operation.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "Element.h"

public class MultiplyOperationElement : public Element {
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
#endif //MULTIPLY_OPERATION_ELEMENT_H