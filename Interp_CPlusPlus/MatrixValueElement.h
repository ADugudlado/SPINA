#ifndef MATRIX_VALUE_ELEMENT_H
#define MATRIX_VALUE_ELEMENT_H

////////////////////////////////////////////////////////////////////////
// MatrixValueElement.h: holds the data needed to represent an Matrix values.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////

#include "Element.h"
#include "Visitor.h"
#include <string>
#include <vector>
#include <sstream>

public class MatrixValueElement : public Element {
private:
   std::string mText;  
   std::vector<std::vector<int>> m;
   void convertTextToMatrix(std::string);
   int parseInt(std::string);
   std::vector<int> rowBuilder(std::string);
public:
  virtual void Accept(Visitor * visitor);
  std::string getText();
  void setText(std::string value);
  std::vector<std::vector<int>> getMatrix();
};

#endif //MATRIX_VALUE_ELEMENT_H