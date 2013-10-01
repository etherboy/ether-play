#include "lamb.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

void LambdaFun()
{
	//no capture, one parameter
	auto aLamb = [](const std::string& aValue){ return aValue + "ly"; };
	std::cout << aLamb("heaven") << std::endl;

	//single value capture, no parameter, mutable
	int aInt = 100;
	auto aLamb2 = [aInt]() mutable { aInt += 10; return aInt; };
	std::cout << "Lamb2: " << aLamb2() << std::endl;

	//single reference capture, single parameter, notice order of evaluation
	auto aLamb3 = [&aInt](int aMultiple) { aInt *= aMultiple; return aInt; };
	std::cout << "Lamb3: " << aLamb3(3) << " again  " << aLamb3(6) << std::endl;

	std::vector<int> aVec = { 24,5,875,43,2,89 };
	std::sort(aVec.begin(), aVec.end(), [](int a1, int a2){ return a1 > a2; } );
	for(int aValue : aVec)
	{
		std::cout << aValue << " ";
	}
	std::cout << std::endl; 
}
