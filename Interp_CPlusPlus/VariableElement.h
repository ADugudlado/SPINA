#ifndef VARIABLE_ELEMENT_H
#define VARIABLE_ELEMENT_H
////////////////////////////////////////////////////////////////////////
// VariableElement.h: holds the data needed to represent variables 
//  in the Interp language.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "Element.h"
#include "Visitor.h"
#include <string>

public class VariableElement : public Element {

private:
   std::string mText;
public:
  virtual void Accept(Visitor * visitor);

  std::string getText();
  void setText(std::string text);
};

#endif //VARIABLE_ELEMENT_H