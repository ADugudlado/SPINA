/** \file
 *  This C header file was generated by $ANTLR version 3.1.3 Mar 18, 2009 10:09:25
 *
 *     -  From the grammar source file : Interp.g
 *     -                            On : 2009-10-09 20:39:27
 *     -                for the parser : InterpParserParser *
 * Editing it, at least manually, is not wise. 
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser InterpParser has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 * 
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pInterpParser, which is returned from a call to InterpParserNew().
 *
 * The methods in pInterpParser are  as follows:
 *
 *  - InterpParser_program_return      pInterpParser->program(pInterpParser)
 *  - InterpParser_expr_return      pInterpParser->expr(pInterpParser)
 *  - InterpParser_matrixassignment_return      pInterpParser->matrixassignment(pInterpParser)
 *  - InterpParser_matrixaddition_return      pInterpParser->matrixaddition(pInterpParser)
 *  - InterpParser_matrixmultiply_return      pInterpParser->matrixmultiply(pInterpParser)
 *  - InterpParser_matrixvariable_return      pInterpParser->matrixvariable(pInterpParser)
 *  - InterpParser_matrixvalue_return      pInterpParser->matrixvalue(pInterpParser)
 *  - InterpParser_matrixprint_return      pInterpParser->matrixprint(pInterpParser)
 *  - InterpParser_assignment_return      pInterpParser->assignment(pInterpParser)
 *  - InterpParser_var_or_int_literal_return      pInterpParser->var_or_int_literal(pInterpParser)
 *  - InterpParser_variable_return      pInterpParser->variable(pInterpParser)
 *  - InterpParser_int_literal_return      pInterpParser->int_literal(pInterpParser)
 *  - InterpParser_addition_return      pInterpParser->addition(pInterpParser)
 *  - InterpParser_multiply_return      pInterpParser->multiply(pInterpParser)
 *  - InterpParser_print_return      pInterpParser->print(pInterpParser)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD licence"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_InterpParser_H
#define _InterpParser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */
 
#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct InterpParser_Ctx_struct InterpParser, * pInterpParser;



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


#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule 
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif
typedef struct InterpParser_program_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    std::vector<Element *> * ret;
}
    InterpParser_program_return;

typedef struct InterpParser_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    Element * ret;
}
    InterpParser_expr_return;

typedef struct InterpParser_matrixassignment_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    MatrixAssignmentOperationElement * ret;
}
    InterpParser_matrixassignment_return;

typedef struct InterpParser_matrixaddition_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    MatrixAdditionOperationElement * ret;
}
    InterpParser_matrixaddition_return;

typedef struct InterpParser_matrixmultiply_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    MatrixMultiplyOperationElement *ret;
}
    InterpParser_matrixmultiply_return;

typedef struct InterpParser_matrixvariable_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    MatrixVariableElement * ret;
}
    InterpParser_matrixvariable_return;

typedef struct InterpParser_matrixvalue_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    MatrixValueElement * ret;
}
    InterpParser_matrixvalue_return;

typedef struct InterpParser_matrixprint_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    MatrixPrintOperationElement * ret;
}
    InterpParser_matrixprint_return;

typedef struct InterpParser_assignment_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    AssignmentOperationElement * ret;
}
    InterpParser_assignment_return;

typedef struct InterpParser_var_or_int_literal_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    Element * ret;
}
    InterpParser_var_or_int_literal_return;

typedef struct InterpParser_variable_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    VariableElement * ret;
}
    InterpParser_variable_return;

typedef struct InterpParser_int_literal_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    IntegerElement * ret;
}
    InterpParser_int_literal_return;

typedef struct InterpParser_addition_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    AdditionOperationElement * ret;
}
    InterpParser_addition_return;

typedef struct InterpParser_multiply_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    MultiplyOperationElement *ret;
}
    InterpParser_multiply_return;

typedef struct InterpParser_print_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
    PrintOperationElement * ret;
}
    InterpParser_print_return;



/** Context tracking structure for InterpParser
 */
struct InterpParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;


     InterpParser_program_return (*program)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_expr_return (*expr)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_matrixassignment_return (*matrixassignment)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_matrixaddition_return (*matrixaddition)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_matrixmultiply_return (*matrixmultiply)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_matrixvariable_return (*matrixvariable)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_matrixvalue_return (*matrixvalue)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_matrixprint_return (*matrixprint)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_assignment_return (*assignment)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_var_or_int_literal_return (*var_or_int_literal)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_variable_return (*variable)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_int_literal_return (*int_literal)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_addition_return (*addition)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_multiply_return (*multiply)	(struct InterpParser_Ctx_struct * ctx);
     InterpParser_print_return (*print)	(struct InterpParser_Ctx_struct * ctx);
    // Delegated rules
    const char * (*getGrammarFileName)();
    void	    (*free)   (struct InterpParser_Ctx_struct * ctx);
    /* @headerFile.members() */
    pANTLR3_BASE_TREE_ADAPTOR	adaptor;
    pANTLR3_VECTOR_FACTORY		vectors;
    /* End @headerFile.members() */
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pInterpParser InterpParserNew         (pANTLR3_COMMON_TOKEN_STREAM instream);
ANTLR3_API pInterpParser InterpParserNewSSD      (pANTLR3_COMMON_TOKEN_STREAM instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the parser will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif 
#define MATRIXVALUE      7
#define RSQBRACKET      12
#define LSQBRACKET      13
#define INT_LITERAL      9
#define T__15      15
#define VARIABLE      8
#define MATRIXVARIABLE      6
#define PRODUCT      11
#define WHITESPACE      14
#define PLUS      10
#define ASSIGNMENT      4
#define EOF      -1
#define END_OF_STATEMENT      5
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for InterpParser
 * =============================================================================
 */
/** \} */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
