////////////////////////////////////////////////////////////////////////
// AdditionOperationElement.cpp: holds the data needed for an addition 
//  operation.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "AdditionOperationElement.h"
#include "Visitor.h"
#include "Element.h"

void AdditionOperationElement::Accept(Visitor * visitor){
  visitor->VisitAdditionOperationElement(this);
}

Element * AdditionOperationElement::getLhs() { 
   return mLhs; 
}

void AdditionOperationElement::setLhs(Element * lhs) { 
   mLhs = lhs; 
}

Element * AdditionOperationElement::getRhs() { 
   return mRhs; 
}

void AdditionOperationElement::setRhs(Element * rhs) { 
   mRhs = rhs; 
}

