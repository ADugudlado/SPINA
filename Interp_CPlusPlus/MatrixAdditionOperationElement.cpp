////////////////////////////////////////////////////////////////////////
// MatrixAdditionOperationElement.cpp: holds the data needed for an addition 
//  operation on matrices.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
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

