#include <string>
#include <vector>

extern short format;
std::string compiler(std::vector<std::string> a) {
	bool infunc;
	std::string ret = "";
	switch (format)
	{
	case 00:
		for (size_t i; i < a.size(); ++i) {
			while (!infunc) {
				if (a.at(i) == "fn") {
					++i;
					ret += a.at(i) += ": \n";
					++i;

				}
				else if (a.at(i) == "IBYTE" || a.at(i) == "UBYTE") {
					++i;
					if (a.at(++i) == "arr") {

					}
				}
			}
		}
		break;
	}
	return ret;
}