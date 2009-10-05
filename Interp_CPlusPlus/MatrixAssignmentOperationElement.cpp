////////////////////////////////////////////////////////////////////////
// MatrixAssignmentOperationElement.cpp: holds the data needed for an 
//  assignment operation.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C# .Net 3.5
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

