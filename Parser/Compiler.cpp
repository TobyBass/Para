#include <string>
#include <vector>

extern short format;
extern std::vector<std::string> types;
extern std::vector<std::string> names;
extern std::vector<std::string> rets;

bool infunc;
std::string compile(std::vector<std::string> a){
	std::string ret = "global _start\n";
	std::string data = "section .data\n";
	std::string text = "section .text\n";
	std::string bss = "section .bss\n";
	switch(format){
		case 0x0000: // x86 nix
			for(size_t i = 0; i < a.size(); ++i){
				if(a.at(i) == "FN"){
					++i;
					ret += a.at(i) += ":\n";
					infunc = true;

				}else if(a.at(i) == "UBYTE" || a.at(i) == "IBYTE"){
					if(infunc){
						++i;
					if(a.at(i + 1) == "arr&" && a.at(i + 3) != "*ptr"){
						std::string d = a.at(i);
						i += 2;
							++i;
							if(a.at(i - 1) == "!ndef"){
								for (int f = 0; f < std::stoi(a.at(i)); ++f){
									ret += d += std::to_string(f) += " db ";
									ret += '""\n';
								}
							}else{
								for (int f = 0; f < std::stoi(a.at(i)); ++f){
									ret += d += std::to_string(f) += " db ";
									ret += a.at(i + f) += "\n";
								}
							}
						
					}else if(a.at(i + 1) == "arr&" && a.at(i + 3) == "*ptr"){
						std::string d = a.at(i);
						i += 2;
						for (int f = 0; f < std::stoi(a.at(i)); ++f)
						{
							ret += d += std::to_string(f); ret += "i dq 0h\n";
							ret += d += std::to_string(f); ret += "ii dq 0h\n";
						}

					}else if(a.at(i + 2) == "*ptr"){
						ret += a.at(i) += "i dq 0h\n";
						ret += a.at(i) += "ii dq 0h\n"; 

					}else if(a.at(i + 2) == "**ptr"){
						ret += a.at(i); ret += "i dq 0h\n"; ret += a.at(i); ret += "ii dq 0h\n"; 
						ret += a.at(i); ret += "iii dq 0h\n"; ret += a.at(i); ret += "iv dq 0h\n";
					}else if(a.at(i + 1) == "arr&&" && a.at(i + 2) == "!ndef"){

						for (int f = 0; f < std::stoi(a.at(i + 3)) * std::stoi(a.at(i + 4)); ++f)
						{
							ret += a.at(i) +=  std::to_string(f) += ' db ""\n';
						}
					}else if(a.at(i + 1) == "arr&&" && a.at(i + 2) != "!ndef"){
						for (int f = 0; f < std::stoi(a.at(i + 3)) * std::stoi(a.at(i + 4)); ++f)
						{
							ret += a.at(i) += std::to_string(f) += ' db "';
							ret += a.at(i + f) += '" \n';
						}
					}else{
						if(a.at(i + 1) == "!ndef"){
							ret += a.at(i) += ' db ""\n';
						}else{
							ret += a.at(i) += ' db "';
							ret += a.at(i + 2) += '"\n';
						} 
					}
				}else{

				}
					

			}
		}
		break;
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;

		case 0x0002: // x86 win
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;

		case 0x0003: // x86 elf win
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;

		case 0x0004: // ARM nix
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x0005: // ARM elf nix
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x0006: // ARM win
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x0007: // ARM elf win
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;

		
		case 0x0008: // IBM nix
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x0009: // IBM elf nix
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x000A: // IBM win
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;

		case 0x000B: // IBM elf win
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x000C: // x86_64
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x000D: // x86 (32-bit)
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x000E: // x86 (16-bit)
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x000F: //ARM
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;

		
		case 0x0010: //IBM
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		case 0x0011: // x86_64 elf
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x0012: // x86 elf (32-bit)
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x0013: // x86 elf (16-bit)
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
		
		case 0x0014: //ARM elf
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;

		
		case 0x0015: //IBM elf
			for(size_t i = 0; i < a.size(); ++i){
				
			}
		break;
	}
	return ret;
}
