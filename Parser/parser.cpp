#include <vector>
#include <string>
#include <stdio.h>

bool doerr;

int inhandle(std::string){
	
} 


std::vector<std::string> Parse(std::vector<std::string> a){
	std::vector<std::string> ret;
	std::vector<std::string> varnames;
	std::vector<const char*> types;
	std::vector<int> invar;
	
	for (int i = 0; i < a.size(); ++i)
	{
		if(a.at(i) == "if"){
			ret.push_back("IF");
			++i;
			if(a.at(i)  == "true" || a.at(i)  == "false"){
				ret.push_back("C");
			}else{
				inhandle(a.at(i));
				if(doerr){
					for(int b = 0; b < varnames.size(); ++b){
						if(a.at(i) == varnames.at(b)){
							
						}
					}
				}
			}
		}
	}
	return ret;
}
