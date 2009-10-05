#ifndef PRINT_OPERATION_ELEMENT_H
#define PRINT_OPERATION_ELEMENT_H
////////////////////////////////////////////////////////////////////////
// PrintOperationElement.h: hold the data needed to implement the
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

public class PrintOperationElement : public Element {

private:
  Element * mChildElement;
public:
  Element * getChildElement();
  void setChildElement(Element * value);

  virtual void Accept(Visitor * visitor);
};

#endif //PRINT_OPERATION_ELEMENT_H