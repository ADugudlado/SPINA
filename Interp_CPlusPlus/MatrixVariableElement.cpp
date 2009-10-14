////////////////////////////////////////////////////////////////////////
// MatrixVariableElement.cpp: holds the data needed to represent matrix variables 
//  in the Interp language.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "MatrixVariableElement.h"
#include "Visitor.h"
#include <string>

void MatrixVariableElement::Accept(Visitor * visitor){
    visitor->VisitMatrixVariableElement(this);
}

std::string MatrixVariableElement::getText() { 
   return mText; 
}

void MatrixVariableElement::setText(std::string text) { 
   text.erase(text.find("[]"),2);
   mText = text; 
}

