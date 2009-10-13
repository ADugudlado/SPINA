////////////////////////////////////////////////////////////////////////
// ParallelforOperationElement.cpp: hold the data needed to implement the
//  'print' function in the Interp language.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "ParallelforOperationElement.h"
#include "VariableElement.h"
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
	end=parseInt(range.substr(range.find(".."),range.length()));
}

void ParallelforOperationElement::setIndexVariableName(VariableElement* variablename){
	indexer=variablename->getText();
}

void ParallelforOperationElement::setBody(std::string body){
	bodyText=body;
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

Element* ParallelforOperationElement::getBody(){
	return elem;
}