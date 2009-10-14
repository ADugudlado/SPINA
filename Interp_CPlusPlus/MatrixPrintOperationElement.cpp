////////////////////////////////////////////////////////////////////////
// MatrixPrintOperationElement.cpp: hold the data needed to implement the
//  'print' function on matrices in the Interp language.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "Element.h"
#include "Visitor.h"
#include "MatrixPrintOperationElement.h"

Element * MatrixPrintOperationElement::getChildElement() { 
   return mChildElement; 
}

void MatrixPrintOperationElement::setChildElement(Element * value) { 
   mChildElement = value; 
}

void MatrixPrintOperationElement::Accept(Visitor * visitor){
  visitor->VisitMatrixPrintOperationElement(this);
}

