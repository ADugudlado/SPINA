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
#include "PrintOperationElement.h"

Element * PrintOperationElement::getChildElement() { 
   return mChildElement; 
}

void PrintOperationElement::setChildElement(Element * value) { 
   mChildElement = value; 
}

void PrintOperationElement::Accept(Visitor * visitor){
  visitor->VisitPrintOperationElement(this);
}

