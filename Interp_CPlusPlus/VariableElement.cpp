////////////////////////////////////////////////////////////////////////
// VariableElement.cpp: holds the data needed to represent variables 
//  in the Interp language.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "VariableElement.h"
#include "Visitor.h"
#include <string>

void VariableElement::Accept(Visitor * visitor){
    visitor->VisitVariableElement(this);
}

std::string VariableElement::getText() { 
   return mText; 
}

void VariableElement::setText(std::string text) { 
   mText = text; 
}

