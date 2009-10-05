#ifndef MATRIX_VARIABLE_ELEMENT_H
#define MATRIX_VARIABLE_ELEMENT_H
////////////////////////////////////////////////////////////////////////
// MatrixVariableElement.h: holds the data needed to represent matrix variables 
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

public class MatrixVariableElement : public Element {

private:
   std::string mText;
public:
  virtual void Accept(Visitor * visitor);

  std::string getText();
  void setText(std::string text);
};

#endif //MATRIX_VARIABLE_ELEMENT_H