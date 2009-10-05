////////////////////////////////////////////////////////////////////////
// PrintOperationElement.cpp: hold the data needed to implement the
//  'print' function in the Interp language.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
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

