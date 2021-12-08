#include "ClassReplace.hpp"

Replace::Replace(void) { return; }

Replace::~Replace(void) { return; }

/*
** Ref:
**	ifs.open: https://www.cplusplus.com/reference/fstream/ifstream/open/
**	ifs.is_open: https://stackoverflow.com/questions/6255339/checking-if-a-file-opened-successfully-with-ifstream
**	ofs.open flags: https://www.cplusplus.com/reference/fstream/ofstream/open/
**	readline: refer to filestreams > isstream.cpp
*/
void Replace::ft_replace(std::string filein, std::string str1, std::string str2)
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string line;

	if (filein.length() == 0)
		throw "Invalid file name";
	else if (str1.empty() || str2.length() == 0)
		throw "Strings mustn't be empty";
	ifs.open(filein.data(), std::ifstream::in);
	if (!ifs.is_open())
		throw "Open infile failed";
	ofs.open((filein + (std::string) ".replace").data(), std::ofstream::out | std::ofstream::trunc);
	if (!ofs.is_open())
		throw "Open outfile failed";
	while (std::getline(ifs, line))
	{
		for (size_t pos = 0;; pos += str2.length())
		{
			pos = line.find(str1, pos);
			if (pos == std::string::npos)
				break;
			line.erase(pos, str1.length());
			line.insert(pos, str2);
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return;
}
