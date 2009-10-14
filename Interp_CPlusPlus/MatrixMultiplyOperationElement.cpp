////////////////////////////////////////////////////////////////////////
// MatrixMultiplyOperationElement.cpp: holds the data needed for an Multiply 
//  operation on matrices.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
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

