#ifndef ELEMENT_H
#define ELEMENT_H
////////////////////////////////////////////////////////////////////////
// Element.h: declares the Accept function that takes a visitor 
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "Visitor.h"

public class Element {

public:
   virtual void Accept(Visitor * visitor) = 0;
};

#endif //ELEMENT_H