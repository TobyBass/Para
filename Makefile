
Para: 
	g++ -O Para Wrapper.cpp Lex.o

lex:
	g++ -C Lex/Lexer.cpp

Parser:
	g++ -C Parser/Parse.cpp

Macro:
	g++ -C Parser/Macro.cpp 

compiler:
	g++ -C Parser/Compiler.cpp

#debugger:

#dissasm:

