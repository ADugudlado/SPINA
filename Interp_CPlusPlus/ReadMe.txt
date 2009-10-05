

Very important:

When you regenerate the parser and lexer you have to remove the lines:

#ifdef __cplusplus
extern "C" {
#endif

and

#ifdef __cplusplus
}
#endif

from InterpParser.h and InterpLexer.h