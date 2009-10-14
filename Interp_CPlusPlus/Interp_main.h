#ifndef INTERP_MAIN_H
#define INTERP_MAIN_H
////////////////////////////////////////////////////////////////////////
// Interp_main.h: It contains Main class which accesses antlr parser and 
// executes the operations depending on the datastructure returned by parser.
// version: 1.1
// 
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <string>
#include "InterpreterVisitor.h"
#include "PrettyPrintVisitor.h"
#include "InterpLexer.h"
#include "InterpParser.h"
#include <antlr3.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;


class Main {
private:
   InterpreterVisitor * interp_visitor;
   PrettyPrintVisitor * print_visitor;
   std::stringstream ss;
   std::streambuf* tempCout;

   std::string convert_to_stdstring(String^ line){
      std::string output = "";
      for(int i = 0; i < line->Length; ++i)
         output += (char) line[i];
      return output;
   }

   void redirectCout(){
	   tempCout=std::cout.rdbuf();
	   std::cout.rdbuf(ss.rdbuf());
   }
public:
   Main(){
      interp_visitor = new InterpreterVisitor();
      print_visitor = new PrettyPrintVisitor();
   }
   void VisitLine(String^ line){
      //source: http://www.antlr.org/wiki/display/ANTLR3/Five+minute+introduction+to+ANTLR+3
   
      std::string stdline = convert_to_stdstring(line);
	  ss.clear();
	  if(stdline=="reset")
		  resetIntrepreter();
      pANTLR3_INPUT_STREAM string_stream;
      pInterpLexer lexer;
      pANTLR3_COMMON_TOKEN_STREAM tokens;
      pInterpParser parser;
      
      string_stream = antlr3NewAsciiStringInPlaceStream((unsigned char *) stdline.c_str(), stdline.size(), NULL);
      lexer = InterpLexerNew(string_stream);
      tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lexer));
      parser = InterpParserNew(tokens);

	  redirectCout();
      std::vector<Element *> * elements = parser->program(parser);
      for(unsigned i = 0; i < elements->size(); i++){
        Element * curr = (*elements)[i];
		try{
        curr->Accept(print_visitor);
        curr->Accept(interp_visitor);
		}
		catch(std::exception E){
			Console::Write("\nInvalid Command\n");
			return;
		}
      }
	  std::string tempstr=ss.str();
		System::String^ t=gcnew String(tempstr.c_str());
		Console::Write(t->ToString());
      parser->free(parser);
      tokens->free(tokens);
      lexer->free(lexer);
      string_stream->close(string_stream);

  }
 
   void resetIntrepreter(){
           interp_visitor = new InterpreterVisitor();
   }
   
};

#endif //INTERP_MAIN_H