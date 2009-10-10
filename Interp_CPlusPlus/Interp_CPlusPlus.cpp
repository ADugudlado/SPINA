// Interp_CPlusPlus.cpp : main project file.

#include "stdafx.h"
#include <string>
#include "InterpreterVisitor.h"
#include "PrettyPrintVisitor.h"
#include "InterpLexer.h"
#include "InterpParser.h"
#include <antlr3.h>

using namespace System;

class Main {
private:
   InterpreterVisitor * interp_visitor;
   PrettyPrintVisitor * print_visitor;

   std::string convert_to_stdstring(String^ line){
      std::string output = "";
      for(int i = 0; i < line->Length; ++i)
         output += (char) line[i];
      return output;
   }
public:
   Main(){
      interp_visitor = new InterpreterVisitor();
      print_visitor = new PrettyPrintVisitor();
   }
   void VisitLine(String^ line){
      //source: http://www.antlr.org/wiki/display/ANTLR3/Five+minute+introduction+to+ANTLR+3
   
      std::string stdline = convert_to_stdstring(line);
      pANTLR3_INPUT_STREAM string_stream;
      pInterpLexer lexer;
      pANTLR3_COMMON_TOKEN_STREAM tokens;
      pInterpParser parser;
      
      string_stream = antlr3NewAsciiStringInPlaceStream((unsigned char *) stdline.c_str(), stdline.size(), NULL);
      lexer = InterpLexerNew(string_stream);
      tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lexer));
      parser = InterpParserNew(tokens);

      std::vector<Element *> * elements = parser->program(parser);
      for(unsigned i = 0; i < elements->size(); i++){
        Element * curr = (*elements)[i];
        curr->Accept(print_visitor);
        curr->Accept(interp_visitor);
      }

      parser->free(parser);
      tokens->free(tokens);
      lexer->free(lexer);
      string_stream->close(string_stream);

  }

   void RunEvalLoop(){
      while(true){
         Console::Write("Interp> ");
         String^ line = Console::ReadLine();
         if(line == "reset")
           interp_visitor = new InterpreterVisitor();
         else
           VisitLine(line);        
       }
   }
};

int main(array<System::String  ^> ^args)
{
   Main themain;
   themain.VisitLine("asasdas");
   themain.RunEvalLoop();
   return 0;
}

//"m[]={1}:{2}:{3};s[]={1,0,0}:{0,1,0}:{0,0,1};m[]=s[]*m[];"