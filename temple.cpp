#include "temple.h"

#include <iostream>
#include <string>

int Run(int aParam)
{
	std::cout << "int " << aParam << std::endl;
	return aParam;
}

int Run(double aParam)
{
	std::cout << "double " << aParam << std::endl;
	return aParam;
}

int Run(double& aParam, std::string& aParam2)
{
	std::cout << "double " << aParam << " string " << aParam2 << std::endl;
	aParam +=15;
	aParam2 += " there";
	
	return aParam;
}

template<typename ...Ts>
int Runner(Ts&& ...aTs)
{
	return Run(std::forward<Ts>(aTs)...);
}

void TempleRun()
{
	double aParam = 7.8;
	std::string aString("hi");
	
	int aResult = Runner(5);
	int aResult2 = Runner(5.6);
	int aResult3 = Runner(aParam, aString);

	std::cout << "Done " << aParam << " and " << aString << std::endl;
}
