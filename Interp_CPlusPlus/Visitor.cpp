////////////////////////////////////////////////////////////////////////
// Visitor.cs: declares all the abstract Visit functions that each
//  visitor must implement.  Also includes the VisitElement function
//  which alows visiting of an Element when its type is not known.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: C# .Net 3.5
////////////////////////////////////////////////////////////////////////
#include "Element.h"
#include "IntegerElement.h"
#include "VariableElement.h"
#include "MatrixVariableElement.h"
#include "MatrixValueElement.h"
#include "MatrixAssignmentOperationElement.h"
#include "MatrixAdditionOperationElement.h"
#include "MatrixMultiplyOperationElement.h"
#include "AdditionOperationElement.h"
#include "AssignmentOperationElement.h"
#include "MultiplyOperationElement.h"

void Visitor::VisitElement(Element * element){
    IntegerElement * int_elem = dynamic_cast<IntegerElement * >(element);
    VariableElement * var_elem = dynamic_cast<VariableElement *>(element);
	MatrixVariableElement * matrixvar_elem = dynamic_cast<MatrixVariableElement *>(element);
	MatrixValueElement * matrixval_elem = dynamic_cast<MatrixValueElement *>(element);
    MatrixAssignmentOperationElement * matrixassign_elem = dynamic_cast<MatrixAssignmentOperationElement *>(element);
	MatrixAdditionOperationElement * matrixadd_elem = dynamic_cast<MatrixAdditionOperationElement *>(element);
	MatrixMultiplyOperationElement * matrixmultiply_elem = dynamic_cast<MatrixMultiplyOperationElement *>(element);
    AdditionOperationElement * add_elem = dynamic_cast<AdditionOperationElement *>(element);
    AssignmentOperationElement * assign_elem = dynamic_cast<AssignmentOperationElement *>(element);
	MultiplyOperationElement * multiply_elem=dynamic_cast<MultiplyOperationElement *>(element);
    if(int_elem != nullptr){
      VisitIntegerElement(int_elem);       
    } else if(var_elem != nullptr){
      VisitVariableElement(var_elem);
	} else if(matrixvar_elem!=nullptr) {
	  VisitMatrixVariableElement(matrixvar_elem);	
	} else if(matrixval_elem!=nullptr){
	  VisitMatrixValueElement(matrixval_elem);	
	} else if(matrixassign_elem!=nullptr){
	  VisitMatrixAssignmentOperationElement(matrixassign_elem);	 
	}else if(matrixadd_elem!=nullptr){
	  VisitMatrixAdditionOperationElement(matrixadd_elem);	 
	}else if(matrixmultiply_elem!=nullptr){
	  VisitMatrixMultiplyOperationElement(matrixmultiply_elem);	 
	}else if(add_elem != nullptr){
      VisitAdditionOperationElement(add_elem);          
    } else if(assign_elem != nullptr){
      VisitAssignmentOperationElement(assign_elem);      
	}else if(multiply_elem!=nullptr){
	  VisitMultiplyOperationElement(multiply_elem);      
	}
}
