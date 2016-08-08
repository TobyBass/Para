#include <string>
#include <vector>

std::vector<std::string> Macro(std::vector<std::string> a){
	std::vector<std::string> defnames;
	std::vector<std::string> defdat;
	bool ranis = false;
	for(size_t I = 0; I < a.size(); ++I){
		if(a.at(I) == "@"){
			++I;
			switch(a.at(I)){
				case "define":
				++I;
				for(size_t i = 0; i < defnames.size(); ++i){
					if(a.at(I) == defnames.at(i)){
						
					}
				}
				break;
				
				case "if":
				
				break;
				
				case "endif":
				
				break;
			}	
		}
  }
}
