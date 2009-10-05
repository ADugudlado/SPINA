////////////////////////////////////////////////////////////////////////
// MatrixMultiplyOperationElement.cpp: holds the data needed for an Multiply 
//  operation.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "MatrixMultiplyOperationElement.h"
#include "Visitor.h"
#include "Element.h"

void MatrixMultiplyOperationElement::Accept(Visitor * visitor){
  visitor->VisitMatrixMultiplyOperationElement(this);
}

Element * MatrixMultiplyOperationElement::getLhs() { 
   return mLhs; 
}

void MatrixMultiplyOperationElement::setLhs(Element * lhs) { 
   mLhs = lhs; 
}

Element * MatrixMultiplyOperationElement::getRhs() { 
   return mRhs; 
}

void MatrixMultiplyOperationElement::setRhs(Element * rhs) { 
   mRhs = rhs; 
}

