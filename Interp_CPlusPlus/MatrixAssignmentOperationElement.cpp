////////////////////////////////////////////////////////////////////////
// MatrixAssignmentOperationElement.cpp: holds the data needed for an 
//  assignment operation on matrices.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language:C++
////////////////////////////////////////////////////////////////////////
#include "MatrixAssignmentOperationElement.h"
#include "Visitor.h"
#include "Element.h"

void MatrixAssignmentOperationElement::Accept(Visitor * visitor){
    visitor->VisitMatrixAssignmentOperationElement(this);
}

MatrixVariableElement * MatrixAssignmentOperationElement::getLhs() { 
   return mLhs; 
}

void MatrixAssignmentOperationElement::setLhs(MatrixVariableElement * lhs) { 
   mLhs = lhs; 
}


Element * MatrixAssignmentOperationElement::getRhs() { 
   return mRhs; 
}

void MatrixAssignmentOperationElement::setRhs(Element * rhs) { 
   mRhs = rhs; 
}

