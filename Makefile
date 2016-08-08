

lex:
	g++ -C Lex/Lexer.cpp

Parser:
	g++ -C Parser/parser.cpp

Macro:
	g++ -C Parser/Macro.cpp 

compiler:
	g++ -C Parser/Compiler.cpp

Para: 
	g++ -o Para Wrapper.cpp Lex.o Compiler.o Macro.o parser.o