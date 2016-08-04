#include "Define.h"
#include <vector>
#include <string>
#include <stdio.h>

extern "C" std::vector<std::string> lex(FILE *)

int main(int argc, const char* argv[]){
  FILE* source;
  bool verbose;
  short format;
  bool debugger;
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
  }else{
  	if(argc == 2){
  		input = argv[1];
  		if(source == NULL){
  			printf(ANSI_COLOR_RED "Fatal Error!" ANSI_COLOR_RESET " No such input file found as ", argv[1], "\n");
  			return 0;
  		}else{
  			
  		}
  	}else{
  		for(int i; i < argc; i++){
  			if(argv[i] == "-I"){
  				i++;
  				input = argv[i];
  			}else{
  			  if(argv[i] == "-O"){
  			    i++;
  			    output = argv[i];
  			  }else{
  			    if(argv[i] == "-D"){
  			      debugger = true;
  			    }else{
  			      if(argv[i] == "-ELF32"){
  			        format = 1;
  			      }else{
  			        if(argv[i] == "-ELF64"){
  			          format = 2;
  			        }else{
  			          if(argv[i] == "-A"){
  			            format = 3;
  			          }else{
  			            if(argv[i] == "-BIN"){
  			              format = 4;
  			            }else{
  			              if(argv[i] == "-DI"){
  			                i++;
  			                DI = argv[i];
  			              }else{
  			                if(argv[i] == "-V"){
  			                  verbose = true;
  			                }else{
  			                  printf("Unkown flag ", argv[i]);
  			                  return 0;
  			                }
  			              }
  			            }
  			          }
  			        }
  			      }
  			    }
  			  }
  			}
  		}
  	}
  }
  return data;
}
