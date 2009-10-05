#ifndef INTEGER_ELEMENT_H
#define INTEGER_ELEMENT_H
////////////////////////////////////////////////////////////////////////
// IntegerElement.h: holds the data needed to represent an Integer.
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

class Element; 

public class IntegerElement : public Element {
private:
   std::string mText;  
public:
  virtual void Accept(Visitor * visitor);

  std::string getText();
  void setText(std::string value);
};

#endif //INTEGER_ELEMENT_H