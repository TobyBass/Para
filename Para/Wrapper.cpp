#include "Define.h"

bool verbose = false;
short format = 00;
bool sasm = false;

int main(int argc, const char* argv[]) {
	FILE* source = NULL;
	const char* output;
	const char* input;
	const char* linker;
	std::string c;
	if (argc == 1) {
		printf("	-I			Input\n");
		printf("	-O			Output\n");
		printf("	-V			Verbose Mode\n");
		printf("	-o			Outputs a object file");
		printf("	-ELF32			Outputs file in elf32 format\n");
		printf("	-ELF64			Outputs file in elf64 format\n");
		printf("	-A			Stops compilation at assembly\n");
		printf("	-BIN			Outputs a .BIN file\n");
		return 0;
	}
	else {
		if (argc == 2) {
			input = argv[1];
			if (source == NULL) {
				SetConsoleTextAttribute(s, RED);
				printf("Fatal Error!");
				SetConsoleTextAttribute(s, WHITE);
				printf(" No such input file found as ", argv[2], "\n");
				return 0;
			}
			else {
				lex(source);
			}
		}
		else {
			for (int i = 0; i < argc; ++i) {
				if (argv[i] == "-I") {
					++i;
					input = argv[i];
				}
				else if (argv[i] == "-O") {
					++i;
					output = argv[i];
				}
				else if (argv[i] == "-V") {
					verbose = true;
				}
				else if (argv[i] == "-o") {
					format = 01;
				}
				else if (argv[i] == "-ELF32") {
					format = 02;
				}
				else if (argv[i] == "-ELF64") {
					format = 03;
				}
				else if (argv[i] == "-A") {
					sasm = true;
				}
				else if (argv[i] == "-BIN") {
					format = 04;
				}
				else {
					c = argv[i];
					if (c.substr(c.size() - 4, c.size()) == ".para") {
						input = c.c_str();

					}
					else if (c.substr(c.size() - 4, c.size()) == ".o" || c.substr(c.size() - 4, c.size()) == ".obj") {
						linker = c.c_str();

					}
				}

			}
		}

	}
	return 0;
}