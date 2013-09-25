#include <iostream>
#include <functional>
#include <algorithm>

int main(int argc, char** argv)
{
	std::cout << "Hello world!" << std::endl;

	int aInts[50] = { 0 };
	int aInc = 5;

	std::generate(std::begin(aInts), std::end(aInts), [&aInc](){ return aInc += 5; });
	
	for(int aVal : aInts)
	{
		std::cout << aVal << ',';
	}

	std::cout << std::endl;
 
	return 0;
}
