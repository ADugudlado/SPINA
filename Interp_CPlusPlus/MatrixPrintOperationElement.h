#ifndef PRINT_OPERATION_MATRIX_ELEMENT_H
#define PRINT_OPERATION_MATRIX_ELEMENT_H

////////////////////////////////////////////////////////////////////////
// MatrixPrintOperationElement.h: hold the data needed to implement the
//  'print' function of matrices in the Interp language.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////

#include "Element.h"
#include "Visitor.h"

public class MatrixPrintOperationElement : public Element {

private:
  Element * mChildElement;
public:
  Element * getChildElement();
  void setChildElement(Element * value);

  virtual void Accept(Visitor * visitor);
};

#endif //PRINT_OPERATION_MATRIX_ELEMENT_H