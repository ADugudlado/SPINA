////////////////////////////////////////////////////////////////////////
// MatrixAdditionOperationElement.cpp: holds the data needed for an addition 
//  operation.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "MatrixAdditionOperationElement.h"
#include "Visitor.h"
#include "Element.h"

void MatrixAdditionOperationElement::Accept(Visitor * visitor){
  visitor->VisitMatrixAdditionOperationElement(this);
}

Element * MatrixAdditionOperationElement::getLhs() { 
   return mLhs; 
}

void MatrixAdditionOperationElement::setLhs(Element * lhs) { 
   mLhs = lhs; 
}

Element * MatrixAdditionOperationElement::getRhs() { 
   return mRhs; 
}

void MatrixAdditionOperationElement::setRhs(Element * rhs) { 
   mRhs = rhs; 
}

