////////////////////////////////////////////////////////////////////////
// ParallelforOperationElement.cpp: hold the data needed to implement the
//  'parallelfor' function in the Interp language.
// 
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "ParallelforOperationElement.h"
#include<sstream>

void ParallelforOperationElement::Accept(Visitor * visitor){
  visitor->VisitParallelforOperationElement(this);
}

int ParallelforOperationElement::parseInt(std::string value){
   std::istringstream iss(value);
   int ret;
   iss >> ret;
   return ret;
}

void ParallelforOperationElement::setIndexRange(std::string range){
	start= parseInt(range.substr(0,range.find("..")));
	end=parseInt(range.substr(range.find("..")+2,range.length()));
}

void ParallelforOperationElement::setIndexVariableName(VariableElement* variablename){
	indexer=variablename->getText();
}

void ParallelforOperationElement::setBody(AssignmentOperationElement* body){
	assign.push_back(body);
}

int ParallelforOperationElement::getStartValue(){
	return start;
}

int ParallelforOperationElement::getEndValue(){
	return end;
}

std::string ParallelforOperationElement::getIndexVariableName(){
	return indexer;
}

vector<AssignmentOperationElement*>& ParallelforOperationElement::getBody(){
	return assign;
}