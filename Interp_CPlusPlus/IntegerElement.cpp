////////////////////////////////////////////////////////////////////////
// IntegerElement.cpp: holds the data needed to represent an Integer.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "IntegerElement.h"
#include "Visitor.h"
#include <string>

void IntegerElement::Accept(Visitor * visitor){
  visitor->VisitIntegerElement(this);
}

std::string IntegerElement::getText() { 
  return mText; 
}

void IntegerElement::setText(std::string value) { 
  mText = value; 
}
