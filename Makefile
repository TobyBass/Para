all: lex Parser Macro MSCG Para clean

lex:
	g++ -std=c++11 -c Lex/Lexer.cpp

Parser:
	g++ -std=c++11 -c Parser/parse.cpp

Macro:
	g++ -std=c++11 -c Parser/Macro.cpp 

MSCG:
	g++ -std=c++11 -c Parser/Compiler.cpp

Para: Lexer.o Compiler.o Macro.o Parser.o
	g++ -std=c++11 -o Para Wrapper.cpp Lexer.o Compiler.o Macro.o parse.o

clean:
	\rm *.o *~ Para
