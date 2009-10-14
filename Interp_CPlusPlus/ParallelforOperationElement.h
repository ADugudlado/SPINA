#ifndef PARALLELFOR_OPERATION_ELEMENT_H
#define PARALLELFOR_OPERATION_ELEMENT_H

////////////////////////////////////////////////////////////////////////
// ParallelforOperationElement.h: hold the data needed to implement the
//  'parallelfor' function in the Interp language.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////

#include "Element.h"
#include "Visitor.h"
#include "VariableElement.h"
#include "AssignmentOperationElement.h"
#include <string>
#include <vector>
using namespace std;

public class ParallelforOperationElement : public Element {

private:
	std::string indexvariable;
	std::string range;
	vector<AssignmentOperationElement *> assign;
	int start,end;
	std::string indexer;
	std::string bodyText;
	int parseInt(std::string);
public:
	void setIndexRange(std::string );
	void setIndexVariableName(VariableElement *);
	void setBody(AssignmentOperationElement *);
	int getStartValue();
	int getEndValue();
	std::string getIndexVariableName();
	vector<AssignmentOperationElement*>& getBody();

  virtual void Accept(Visitor * visitor);
};

#endif //PARALLELFOR_OPERATION_ELEMENT_H