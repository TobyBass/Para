#include "C:\Users\toby\Documents\GitHub\Para\Para\Para/Parser.h"


bool doerr;
//order of operations


int inhandle(std::string){
	return 0;
} 

int data = 1;

std::vector<std::string> Parse(std::vector<std::string> a){
	std::vector<std::string> funcnames;
	int multiplier = 1;
	bool unsign = false;
	std::vector<std::string> ret;
	std::vector<std::string> types;
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

				}
				else {
					ret.push_back("UBYTE");
				}
			}
			else if (multiplier > 1) {

			}
		}
	}
	return ret;
}
