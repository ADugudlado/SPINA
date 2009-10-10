////////////////////////////////////////////////////////////////////////
// AssignmentOperationElement.cpp: holds the data needed for an 
//  assignment operation.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C# .Net 3.5
////////////////////////////////////////////////////////////////////////
#include "AssignmentOperationElement.h"
#include "Visitor.h"
#include "Element.h"

void AssignmentOperationElement::Accept(Visitor * visitor){
    visitor->VisitAssignmentOperationElement(this);
}

VariableElement * AssignmentOperationElement::getLhs() { 
   return mLhs; 
}

MatrixVariableElement * AssignmentOperationElement::getMatrixLhs() { 
   return matrixmLhs; 
}

void AssignmentOperationElement::setLhs(VariableElement * lhs) { 
   mLhs = lhs; 
}
void AssignmentOperationElement::setMatrixLhs(MatrixVariableElement * lhs) { 
   matrixmLhs= lhs; 
}


Element * AssignmentOperationElement::getRhs() { 
		return mRhs; 
}

void AssignmentOperationElement::setRhs(Element * rhs) { 
   mRhs = rhs; 
}

