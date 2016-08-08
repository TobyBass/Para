#include <string>
#include <vector>

std::vector<std::string> Macro(std::vector<std::string> a){
	for(size_t I = 0; I < a.size(); ++I){
		if(a.at(I) == "@"){
			++I;
			switch(a.at(I)){
				case "define":
				++I;
				
				break;
				
				case "if":
				
				break;
				
				case "endif":
				
				break;
			}	
		}
  }
}
