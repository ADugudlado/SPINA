////////////////////////////////////////////////////////////////////////
// PrettyPrintVisitor.cpp: demonstrates printing the syntax tree in 
//  a difference source language than the input for the Interp language.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "PrettyPrintVisitor.h"

void PrettyPrintVisitor::VisitVariableElement(VariableElement * element){
   std::cout << "var:" + element->getText() + " ";
}
void PrettyPrintVisitor::VisitMatrixVariableElement(MatrixVariableElement * element){
   std::cout << "matvar:" + element->getText() + " ";
}
void PrettyPrintVisitor::VisitMatrixValueElement(MatrixValueElement * element){
    std::cout << "matrix values:" ;
	std::vector<std::vector<int>> printmatrix=element->getMatrix();
	std::cout<<"\nOrder of Matrix :"<<printmatrix.size()<<" x "<<printmatrix.begin()->size()<<" \n";
	for(unsigned i=0;i<printmatrix.size();i++){
		for(unsigned j=0;j<printmatrix[i].size();j++){
			std::cout<<printmatrix[i][j]<<" ";
		}
		std::cout<<"\n";
	}
}
void PrettyPrintVisitor::VisitMatrixAssignmentOperationElement(MatrixAssignmentOperationElement * element){
	VisitElement(element->getLhs());
    std::cout << ":= ";
    VisitElement(element->getRhs());
    std::cout << ";" <<std::endl;
}
void PrettyPrintVisitor::VisitIntegerElement(IntegerElement * element){
    std::cout << "int:" + element->getText() + " ";
}
void PrettyPrintVisitor::VisitAssignmentOperationElement(AssignmentOperationElement * element){
    VisitElement(element->getLhs());
    std::cout << ":= ";
    VisitElement(element->getRhs());
    std::cout << ";" <<std::endl;
}
void PrettyPrintVisitor::VisitAdditionOperationElement(AdditionOperationElement * element){
    VisitElement(element->getLhs());
    std::cout << "+ ";
    VisitElement(element->getRhs());
    std::cout << " ";
}
void PrettyPrintVisitor::VisitPrintOperationElement(PrintOperationElement * element){
    std::cout << "function:print ";
    VisitElement(element->getChildElement());
    std::cout << ";" << std::endl;
}
void PrettyPrintVisitor::VisitMatrixPrintOperationElement(MatrixPrintOperationElement * element){
    std::cout << "function:print ";
    VisitElement(element->getChildElement());
    std::cout << ";" << std::endl;
}
void PrettyPrintVisitor::VisitMultiplyOperationElement(MultiplyOperationElement * element){
    VisitElement(element->getLhs());
    std::cout << "* ";
    VisitElement(element->getRhs());
    std::cout << " ";
}
void PrettyPrintVisitor::VisitMatrixAdditionOperationElement(MatrixAdditionOperationElement * element){
    VisitElement(element->getLhs());
    std::cout << "+ ";
    VisitElement(element->getRhs());
    std::cout << " ";
}
void PrettyPrintVisitor::VisitMatrixMultiplyOperationElement(MatrixMultiplyOperationElement * element){
    VisitElement(element->getLhs());
    std::cout << "* ";
    VisitElement(element->getRhs());
    std::cout << " ";
}
void PrettyPrintVisitor::VisitParallelforOperationElement(ParallelforOperationElement * element){
	std::cout<<"\nParallel-for : index variable -"<<element->getIndexVariableName();
	std::cout<<" from "<<element->getStartValue()<<" to "<<element->getEndValue();
	std::cout<<"\nBody : \n"<<element->getBody();
}