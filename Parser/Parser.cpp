#include "Parser.h"

std::vector<std::string> Parse(std::vector<std::string> a);

int inhandle(std::string a);

std::vector<std::string> oorp(std::vector<std::string> v);

bool doerr;

bool infunc;
/*
()
^
/
*
|
xor
&
-
+
$
%
*/
//Order of operations
std::vector<std::string> oorp(std::vector<std::string> v){
	std::vector<std::string> ret;
	for(size_t i = 0; i < v.size(); ++i){

	}
	return ret;
}

int inhandle(std::string a){
	int b = 0;
	if(a.at(a.size()) == 'O' || a.at(a.size()) == 'o' ){
		b= std::stoi(a.substr(1,a.size()-1), nullptr, 8);
	}else if(a.at(a.size()) == 'B' || a.at(a.size()) == 'b' ){
		b= std::stoi(a.substr(1,a.size()-1), nullptr, 2);
	}else if(a.at(a.size()) == 'D' || a.at(a.size()) == 'd' ){
		b= std::stoi(a.substr(1,a.size()-1), nullptr, 10);
	}else if(a.at(2) == 'X' || a.at(2) == 'x'){
		a = a.substr(3, a.size());
		b = std::stoi(a, nullptr, 16);
	}else{
		b = std::stoi(a, nullptr, 10);
	}
	return b;
} 

int data = 1;

std::vector<std::string> types;
std::vector<std::string> names;
std::vector<std::string> rets;

std::vector<std::string> Parse(std::vector<std::string> a){
	std::vector<std::string> funcnames;
	std::vector<std::vector<std::string> > funcvars;
	std::vector<std::string> usdeftype;
	int multiplier = 1;
	bool unsign = false;
	bool infunc = false;
	std::vector<std::string> ret;
	for (int i = 0; i < a.size(); ++i)
	{
		if(a.at(i) == "fn"){
			if(infunc){

			}else{
			ret.push_back("FN");
			++i;
			if (unsign) {
				printf(ANSI_COLOR_RED "Error! " ANSI_COLOR_RESET "You cannot make a unsigned function");
				unsign = false;
			}
			if (a.at(i) == "byte" || a.at(i) == "int" || a.at(i) == "bool" || a.at(i) == "short" || a.at(i) == "signed" || a.at(i) == "unsigned" || a.at(i) == "float") {
				doerr = true;
			}
			else {
				for (int d = 0; d < types.size(); ++d) {
					if (a.at(i) == types.at(d)) doerr = true;
				}
				if (doerr) {
					printf(ANSI_COLOR_RED "Error! " ANSI_COLOR_RESET "You cannot name a function as type\n");					doerr = true;
				}
				else {
					if (a.at(i) == "!" || a.at(i) == "@" || a.at(i) == "$" || a.at(i) == "%" || a.at(i) == "^" || a.at(i) == "&" || a.at(i) == "*" || a.at(i) == "(" || a.at(i) == ")" || a.at(i) == "-" || a.at(i) == "+" || a.at(i) == "/" || a.at(i) == "<" || a.at(i) == ">" || a.at(i) == "," || a.at(i) == "." || a.at(i) == "{" || a.at(i) == "}" || a.at(i) == "[" || a.at(i) == "]" || a.at(i) == "|" || a.at(i) == ":" || a.at(i) == "\n") {
						printf(ANSI_COLOR_RED "Error! " ANSI_COLOR_RESET "You cannot name a function as a symbol/n");
						doerr = true;
					}
					else {
						for (int e = 0; e < funcnames.size(); ++e) {
							if (e != e) {
							
							}
							else if (funcnames.at(e) == a.at(i)) {
									doerr = true;
									
									printf(ANSI_COLOR_RED "Error! " ANSI_COLOR_RESET "You've already defined a function named %s", a.at(i).c_str(), "\n");
							}
							else {
								ret.push_back(a.at(i));
								funcnames.push_back(a.at(i));
							}
						}

					}
				}
			}
		}
		}
		else if (a.at(i) == "long") {
			multiplier = 2;
			while (a.at(i) == "long") {
				multiplier = multiplier * 2;
				++i;
			}
			
		}
		else if (a.at(i) == "unsigned") unsign = true;
		else if (a.at(i) == "byte") {
			if (unsign) {
				if (multiplier > 1) {
					ret.push_back("UBYTE_");
					ret.push_back(std::to_string(inhandle(a.at(i))));
				}
				else {
					ret.push_back("UBYTE");
				}
			}
			else if (multiplier > 1) {
				ret.push_back("IBYTE_");
			}
			++i;
			if(a.at(i) != "["){
			for(int f; f < names.size(); ++f){
				if(a.at(i) == names.at(f)) doerr = true;
			}
			if(doerr){
				printf(ANSI_COLOR_RED "Error! " ANSI_COLOR_RESET "You've already defined a variable named %s", a.at(i).c_str(), "\n");
			}else{
				++i;
				names.push_back(a.at(i));
				ret.push_back(a.at(i));
				if(a.at(i) == "="){
				++i;
				if(a.at(i) == "'" || a.at(i).at(1) == '"'){

				}
			}else if(a.at(i) == "\n"){
				ret.push_back("!ndef");
			}else if(a.at(i) == "*"){

				if(a.at(i + 1) == "*"){
					ret.push_back("**ptr");
				}else{
					ret.push_back("*ptr");
				}

			}

			}
			}else{
				++i;
				if(a.at(i + 2) == "["){
					ret.push_back("&&arr");
					++i;
					if(a.at(i) == "]"){
						doerr = true;
						printf("\n");
					}
				}else if(a.at(i) == "]"){

				}
			}
		}
	}
	if(doerr){
		for (int i = 0; i < ret.size(); ++i)
		{
			//ret.assign()
		}
	}
	return ret;
}
