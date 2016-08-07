#include "C:\Users\toby\Documents\GitHub\Para\Para\Para/Parser.h"


bool doerr;
//order of operations


int inhandle(std::string){
	return 0;
} 

int data = 1;

std::vector<std::string> Parse(std::vector<std::string> a){
	std::vector<std::string> funcnames;
	std::vector<std::string> rets;
	int multiplier = 1;
	bool unsign = false;
	int rand = 0;
	std::vector<std::string> ret;
	std::vector<std::string> types;
	std::vector<std::string> varnames;
	bool infunc = false;
	for (int i = 0; i < a.size(); ++i)
	{
		if(a.at(i) == "fn"){
			ret.push_back("fn");
			++i;
			if (unsign) {
				SetConsoleTextAttribute(s, RED);
				printf("Error! ");
				SetConsoleTextAttribute(s, WHITE);
				printf("You just defined a unsinged function!");
				unsign = false;
			}
			if (a.at(i) == "byte" || a.at(i) == "int" || a.at(i) == "bool" || a.at(i) == "short" || a.at(i) == "signed" || a.at(i) == "unsigned" || a.at(i) == "float") {
				SetConsoleTextAttribute(s, RED);
				printf("Error! ");
				SetConsoleTextAttribute(s, WHITE);
				printf("You cannot name a function as type\n");
				doerr = true;
			}
			else {
				for (int d = 0; d < types.size(); ++d) {
					if (a.at(i) == types.at(d)) doerr = true;
				}
				if (doerr) {
					SetConsoleTextAttribute(s, RED);
					printf("Error! ");
					SetConsoleTextAttribute(s, WHITE);
					printf("You cannot name a function as type\n");
					doerr = true;
				}
				else {
					if (a.at(i) == "!" || a.at(i) == "@" || a.at(i) == "$" || a.at(i) == "%" || a.at(i) == "^" || a.at(i) == "&" || a.at(i) == "*" || a.at(i) == "(" || a.at(i) == ")" || a.at(i) == "-" || a.at(i) == "+" || a.at(i) == "/" || a.at(i) == "<" || a.at(i) == ">" || a.at(i) == "," || a.at(i) == "." || a.at(i) == "{" || a.at(i) == "}" || a.at(i) == "[" || a.at(i) == "]" || a.at(i) == "|" || a.at(i) == ":" || a.at(i) == "\n") {
						SetConsoleTextAttribute(s, RED);
						printf("Error! ");
						SetConsoleTextAttribute(s, WHITE);
						printf("You cannot name a function as a symbol/n");
						doerr = true;
					}
					else {
						for (int e = 0; e < funcnames.size(); ++e) {
							if (e != e) {
								// HOLY SHIT
							}
							else if (funcnames.at(e) == a.at(i)) {
									doerr = true;
									SetConsoleTextAttribute(s, RED);
									printf("Error! ");
									SetConsoleTextAttribute(s, WHITE);
									printf("You've alread made a function titled %s", a.at(i).c_str(), "\n");
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
					if (multiplier >= 100000 && verbose) {
						SetConsoleTextAttribute(s, YELLOW);
						printf("Warning! ");
						SetConsoleTextAttribute(s, WHITE);
						printf("You are allocating over a megabyte of memory for a single varible");
					}
					ret.push_back("UBYTE_");
					ret.push_back(std::to_string(multiplier));
				}
				else {
					ret.push_back("UBYTE");
				}
			}
			else if (multiplier > 1) {
				ret.push_back("IBYTE_");
				ret.push_back(std::to_string(multiplier));
			}
			else {
				ret.push_back("IBYTE");
			}
			++i;
			if (a.at(i) == "!" || a.at(i) == "@" || a.at(i) == "$" || a.at(i) == "%" || a.at(i) == "^" || a.at(i) == "&" || a.at(i) == "*" || a.at(i) == "(" || a.at(i) == ")" || a.at(i) == "-" || a.at(i) == "+" || a.at(i) == "/" || a.at(i) == "<" || a.at(i) == ">" || a.at(i) == "," || a.at(i) == "." || a.at(i) == "{" || a.at(i) == "}" || a.at(i) == "[" || a.at(i) == "]" || a.at(i) == "|" || a.at(i) == ":" || a.at(i) == "\n") {
				SetConsoleTextAttribute(s, RED);
				printf("Error! ");
				SetConsoleTextAttribute(s, WHITE);
				printf("You cannot name a variable as a symbol\n");
			}
			else {
				for (size_t k = 0; k < varnames.size(); k++)
				{
					if (varnames.at(k) == a.at(i)) doerr = true;
				}
				if (doerr) {
					SetConsoleTextAttribute(s, RED);
					printf("Error! ");
					SetConsoleTextAttribute(s, WHITE);
					printf("You have already defined a variable named %s", a.at(i).c_str() , "\n");
				}
				else {
					if (a.at(++i) == "(") {
						ret.push_back("fn");
						doerr = true;
						for (size_t j = 0; j < types.size(); ++j) {
							if (ret.at(ret.size() - 1) == types.at(j)) {
								doerr = false;
							}
						}
						if (!doerr) {
							rets.push_back(ret.at(ret.size() - 1));

						}
						else {
							rets.push_back(ret.at(ret.size() - 1) += ret.at(ret.size() - 2));
						}
						funcnames.push_back(a.at(i));
					}
					else {
						varnames.push_back(a.at(i));
						ret.push_back(a.at(i));
						++i;
						if (a.at(i) == "[") {
							ret.push_back("arr");
							++i;
							if (a.at(i) == "]") {
								int m = i;
								while (a.at(m) != "}") {
									if (a.at(m) == ",") {
										rand =+ 1;
									}
									++m;
								}
							}
							else {
								ret.push_back(a.at(i));
							}
						}
					}
				}
			}
		}
	}
	return ret;
}
