#include <iostream>
#include <fstream>

/*
** ifs/ofs: input/output file stream
** Look into the doc on opening and closing streams; also, (i/o)stringstreams
*/
int main()
{
	std::ifstream ifs("numbers");
	unsigned int dst;
	unsigned int dst2;
	ifs >> dst >> dst2;

	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();

	//-----------------------

	std::ofstream ofs("test.out");

	ofs << "i like ponies a whole damn lot" << std::endl;
	ofs.close();
}
