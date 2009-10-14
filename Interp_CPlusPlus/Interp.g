////////////////////////////////////////////////////////////////////////
// Interp.g: creates a parser for the Interp language.
// 
// version: 1.0
// description: part of the interpreter example for the visitor design
//  pattern.
// author: phil pratt-szeliga (pcpratts@syr.edu)
// language: antlr 3.0.1 parser generator - grammer input
////////////////////////////////////////////////////////////////////////

grammar Interp;

options {
  language = 'C';
} 

@parser::header {
#include <vector>
#include<iostream>
#include "Element.h"
#include "VariableElement.h"
#include "MatrixVariableElement.h"
#include "MatrixValueElement.h"
#include "MatrixAssignmentOperationElement.h"
#include "MatrixPrintOperationElement.h"
#include "MatrixMultiplyOperationElement.h"
#include "MatrixAdditionOperationElement.h"
#include "IntegerElement.h"
#include "AssignmentOperationElement.h"
#include "AdditionOperationElement.h"
#include "PrintOperationElement.h"
#include "MultiplyOperationElement.h"
#include "ParallelforOperationElement.h"
}

@lexer::header {
#include <vector>
#include<iostream>
#include "Element.h"
#include "VariableElement.h"
#include "IntegerElement.h"
#include "MatrixValueElement.h"
#include "MatrixVariableElement.h"
#include "MatrixAssignmentOperationElement.h"
#include "MatrixPrintOperationElement.h"
#include "MatrixMultiplyOperationElement.h"
#include "MatrixAdditionOperationElement.h"
#include "AssignmentOperationElement.h"
#include "AdditionOperationElement.h"
#include "PrintOperationElement.h"
#include "MultiplyOperationElement.h"
#include "ParallelforOperationElement.h"
}

/*
 * Parser Rules
 */
program returns [std::vector<Element *> * ret]
@init{
  ret = new std::vector<Element *>();
}
  : (expr {ret->push_back($expr.ret); } )+;
   
   
 

expr returns [Element * ret]
  : assignment {ret = $assignment.ret;}
  | matrixassignment {ret=$matrixassignment.ret;}
  | print { ret = $print.ret; }
  | matrixprint { ret = $matrixprint.ret; }
  | parallelfor { ret = $parallelfor.ret; };

parallelfor returns [ParallelforOperationElement * ret]
@init {
	ret=new ParallelforOperationElement();
}
 : 'parallelfor' '('
    variable {ret->setIndexVariableName($variable.ret);} 
	WHITESPACE
	RANGE     {pANTLR3_STRING str = $RANGE.text;
	       char * chars = (char *) str->chars;
               ret->setIndexRange(std::string(chars)); }
	')'
	'{'
	 (assignment {ret->setBody($assignment.ret);})+
	'}'
	END_OF_STATEMENT;
	  
matrixassignment returns [MatrixAssignmentOperationElement * ret]
@init {
  ret = new MatrixAssignmentOperationElement();
}
  : matrixvariable {ret->setLhs($matrixvariable.ret); }
    ASSIGNMENT 
	(matrixvalue {ret->setRhs($matrixvalue.ret); } 		
	 |matrixaddition {ret->setRhs($matrixaddition.ret);}
	 |matrixmultiply {ret->setRhs($matrixmultiply.ret);} 
    ) END_OF_STATEMENT;
	
	
matrixaddition returns [MatrixAdditionOperationElement * ret]
@init {
  ret = new MatrixAdditionOperationElement();
}
  : el1=matrixvariable { ret->setLhs($el1.ret); } 
    '+' 
    el2=matrixvariable { ret->setRhs($el2.ret); };

matrixmultiply returns [MatrixMultiplyOperationElement *ret]	
@init {
   ret=new MatrixMultiplyOperationElement();
}
: el1=matrixvariable { ret->setLhs($el1.ret); } 
    '*' 
  el2=matrixvariable { ret->setRhs($el2.ret); };

matrixvariable returns [MatrixVariableElement * ret]	
@init {
  ret = new MatrixVariableElement();
}
	: MATRIXVARIABLE{
				   pANTLR3_STRING str = $MATRIXVARIABLE.text;
				char * chars = (char *) str->chars;
				ret->setText(std::string(chars));};
				
matrixvalue returns [MatrixValueElement * ret]
@init {
   ret=new MatrixValueElement();
}
 : MATRIXVALUE {pANTLR3_STRING str = $MATRIXVALUE.text;
				char * chars = (char *) str->chars;
				ret->setText(std::string(chars));};
	
matrixprint returns [MatrixPrintOperationElement * ret]
@init {
  ret = new MatrixPrintOperationElement();
}
  : 'print' matrixvariable {ret->setChildElement($matrixvariable.ret); }
    END_OF_STATEMENT; 
	
assignment returns [AssignmentOperationElement * ret]
@init {
  ret = new AssignmentOperationElement();
}
  : variable {ret->setLhs($variable.ret); }
    ASSIGNMENT 
	(var_or_int_literal {ret->setRhs($var_or_int_literal.ret); } 		
    |addition {ret->setRhs($addition.ret);}
	|multiply {ret->setRhs($multiply.ret);}
    ) END_OF_STATEMENT;

var_or_int_literal returns [Element * ret]
  :  (variable { ret = $variable.ret; } 
  |   int_literal {ret = $int_literal.ret; } );


variable returns [VariableElement * ret]
@init {
  ret = new VariableElement();
}
  : VARIABLE { pANTLR3_STRING str = $VARIABLE.text;
	       char * chars = (char *) str->chars;
               ret->setText(std::string(chars)); };
				
				
int_literal returns [IntegerElement * ret]
@init {
  ret = new IntegerElement();
}
  : INT_LITERAL { pANTLR3_STRING str = $INT_LITERAL.text;
	       char * chars = (char *) str->chars;
               ret->setText(std::string(chars)); };

			   
			   
addition returns [AdditionOperationElement * ret]
@init {
  ret = new AdditionOperationElement();
}
  : el1=var_or_int_literal { ret->setLhs($el1.ret); } 
    '+' 
    el2=var_or_int_literal { ret->setRhs($el2.ret); };

multiply returns [MultiplyOperationElement *ret]	
@init {
   ret=new MultiplyOperationElement();
}
: el1=var_or_int_literal { ret->setLhs($el1.ret); } 
    '*' 
  el2=var_or_int_literal { ret->setRhs($el2.ret); };
	
print returns [PrintOperationElement * ret]
@init {
  ret = new PrintOperationElement();
}
  : 'print' var_or_int_literal {ret->setChildElement($var_or_int_literal.ret); }
    END_OF_STATEMENT; 


/*
 * Lexer Rules
 */

END_OF_STATEMENT: ';';
ASSIGNMENT: '=';
PLUS: '+';
PRODUCT: '*';
RSQBRACKET: ']';
LSQBRACKET: '[';
VARIABLE: ('a'..'z' | 'A'..'Z' )+;
INT_LITERAL: ('0'..'9')+;
WHITESPACE : (' ' | '\t' | '\n' | '\r' )+ {$channel = HIDDEN; } ;
MATRIXVARIABLE:VARIABLE LSQBRACKET RSQBRACKET;
MATRIXVALUE: (('{'(INT_LITERAL ',')* INT_LITERAL'}')':')* ('{'(INT_LITERAL ',')* INT_LITERAL'}');
RANGE: INT_LITERAL '..' INT_LITERAL;
