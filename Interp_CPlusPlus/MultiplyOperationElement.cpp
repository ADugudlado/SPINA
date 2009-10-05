////////////////////////////////////////////////////////////////////////
// MultiplyOperationElement.cpp: holds the data needed for an Multiply 
//  operation.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "MultiplyOperationElement.h"
#include "Visitor.h"
#include "Element.h"

void MultiplyOperationElement::Accept(Visitor * visitor){
  visitor->VisitMultiplyOperationElement(this);
}

Element * MultiplyOperationElement::getLhs() { 
   return mLhs; 
}

void MultiplyOperationElement::setLhs(Element * lhs) { 
   mLhs = lhs; 
}

Element * MultiplyOperationElement::getRhs() { 
   return mRhs; 
}

void MultiplyOperationElement::setRhs(Element * rhs) { 
   mRhs = rhs; 
}

