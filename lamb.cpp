#include "lamb.h"

#include <string>
#include <iostream>

void LambdaFun()
{
	//no capture, one parameter
	auto aLamb = [](const std::string& aValue){ return aValue + "ly"; };
	std::cout << aLamb("heaven") << std::endl; 
}
