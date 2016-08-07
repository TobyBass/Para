#pragma once
#include <vector>
#include <string>
#include <stdio.h>


std::vector<std::string> lex(FILE* fp)
{
	std::vector<std::string> endup;
	bool inq = false;
	bool rando = false;
	char* a = "";
	if (fgets(a, 100000, fp) != NULL) {
		puts(a);
		fclose(fp);
	}
	std::string file = a;
	std::string temptoke;
	std::string b = "";
	std::string c[] = { "byte", "int", "bool", "string", "if", "while", "for", "else", "class", "fn", "unsigned", "signed", "define", "return", "const", "import", "null", "asm", "float", "false", "true", "xor", "new", "short", "public", "private", "break", "do", "object", "vector", "delete", "try", "catch", "size", "long", "double", "protected", "alloc", "enum", "restore", "endif", "static", "dealloc" };
	std::vector<std::string> lexic;
	for (int C = 0; C < file.size(); C++) {
		if (inq) {
			if (file.at(C) == '"') {
				b += file.at(C);
				endup.push_back(temptoke);
				endup.push_back(b);
				inq = false;
				b = "";
			}
			else {
				b += file.at(C);
				if (b == "'") {
					endup.push_back(temptoke);
					endup.push_back(b);
					inq = false;
					b = "";
				}
				else {
					temptoke += file.at(C);
					b = "";
				}
			}
		}
		else {
			if (file.at(C) == '"') {
				b += file.at(C);
				endup.push_back(temptoke);
				endup.push_back(b);
				inq = true;
				b = "";
			}
			else {
				b += file.at(C);
				if (b == "'") {
					endup.push_back(temptoke);
					endup.push_back(b);
					inq = true;
					b = "";
				}
				else {
					temptoke += file.at(C);
					b = "";
				}
				if (file.at(C) == ' ' || file.at(C) == '\t') {
					C++;
				}
				else {
					if (file.at(C) == '!' || file.at(C) == '@' || file.at(C) == '$' || file.at(C) == '%' || file.at(C) == '^' || file.at(C) == '&' || file.at(C) == '*' || file.at(C) == '(' || file.at(C) == ')' || file.at(C) == '-' || file.at(C) == '+' || file.at(C) == '/' || file.at(C) == '<' || file.at(C) == '>' || file.at(C) == '{' || file.at(C) == '}' || file.at(C) == '[' || file.at(C) == ']' || file.at(C) == ':' || file.at(C) == '\n') {
						endup.push_back(temptoke);
						temptoke = file.at(C);
						endup.push_back(temptoke);
						temptoke = "";
					}
					else {
						for (int A = 0; A < lexic.size(); A++) {
							if (temptoke == lexic.at(A)) {
								endup.push_back(temptoke);
								temptoke = "";
								rando = true;
							}
						}
					}
					if (temptoke == "typedef") {
						endup.push_back(temptoke);
						temptoke = "";
						while (true) {
							C++;
							if (file.at(C) == '!' || file.at(C) == '@' || file.at(C) == '$' || file.at(C) == '%' || file.at(C) == '^' || file.at(C) == '&' || file.at(C) == '*' || file.at(C) == '(' || file.at(C) == ')' || file.at(C) == '-' || file.at(C) == '+' || file.at(C) == '/' || file.at(C) == '<' || file.at(C) == '>' || file.at(C) == '{' || file.at(C) == '}' || file.at(C) == '[' || file.at(C) == ']' || file.at(C) == ':' || file.at(C) == '\n') {
								endup.push_back(temptoke);
								lexic.push_back(temptoke);
								temptoke = file.at(C);
								endup.push_back(temptoke);
								temptoke = "";
								break;
							}
							else {
								if (file.at(C) == ' ' || file.at(C) == ' ') {
									C++;
								}
								else {
									temptoke += file.at(C);
								}
							}

						}
					}
					else {
						rando = false;
						for (size_t d = 0; d < sizeof(c); d++) {
							if (temptoke == c[d]) {
								rando = true;
								endup.push_back(temptoke);
							}
						}
					}
				}
			}
		}

	}
	return endup;
}
