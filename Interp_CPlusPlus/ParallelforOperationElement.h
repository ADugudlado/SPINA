#ifndef PARALLELFOR_OPERATION_ELEMENT_H
#define PARALLELFOR_OPERATION_ELEMENT_H
////////////////////////////////////////////////////////////////////////
// ParallelforOperationElement.h: hold the data needed to implement the
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
#include <string>
using namespace std;

public class ParallelforOperationElement : public Element {

private:
	std::string indexvariable;
	std::string range;
	Element *elem;
	int start,end;
	std::string indexer;
	std::string bodyText;
	int parseInt(std::string);
public:
	void setIndexRange(std::string );
	void setIndexVariableName(VariableElement *);
	void setBody(std::string);
	int getStartValue();
	int getEndValue();
	std::string getIndexVariableName();
	Element* getBody();

  virtual void Accept(Visitor * visitor);
};

#endif //PARALLELFOR_OPERATION_ELEMENT_H