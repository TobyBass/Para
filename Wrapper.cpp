#include "Define.h"



FILE* source;
bool isverbose;
short format;

int main(int argc, const char* argv[]){
  const char* output;
  const char* input;
  const char* DI;
  if(argc == 1){
    printf("	-I			Input\n");
    printf("	-O			Output\n");
    printf("	-V			Verbose Mode\n");
    printf("	-D			Debugger\n");
    printf("	-ELF32			Outputs file in elf32 format\n");
    printf("	-ELF64			Outputs file in elf64 format\n");
    printf("	-A			Stops compilation at assembly\n");
    printf("	-BIN			Outputs a .BIN file\n");
    printf("	-DI			Debug Input Executable\n");
    return 0;
  }else if(argc == 2){
    input = argv[1];
    if(source == NULL){
    printf(ANSI_COLOR_RED "Fatal Error!" ANSI_COLOR_RESET " No such input file found as ", argv[1], "\n");
    return 0;
  }
  }else{
    for(int i; i < argc; i++){

    }
}
  return data;
}
