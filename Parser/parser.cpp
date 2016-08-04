#include <vector>
#include <string>
#include <stdio.h>

bool doerr;
//order of operations


int inhandle(std::string){
	
} 

std::vector<std::string> Parse(std::vector<std::string> a){
	std::vector<std::string> ret;
	
	for (int i = 0; i < a.size(); ++i)
	{
		if(a.at(i) == "fn"){
			ret.push_back("fn");
			
		}
	}
	return ret;
}
