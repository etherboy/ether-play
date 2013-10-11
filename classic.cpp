#include "classic.h"

#include <iostream>
#include <algorithm>

CBigBugger::CBigBugger() : mElementCount(0)
{
}

CBigBugger::CBigBugger(std::initializer_list<int> aList) : mElementCount(aList.size()), mpBigCollection(new int[mElementCount])
{
	std::copy(aList.begin(), aList.end(), &mpBigCollection[0]);
}

CBigBugger::CBigBugger(CBigBugger&& aOther) : mElementCount(aOther.mElementCount)
{
	mpBigCollection.swap(aOther.mpBigCollection);
}


CBigBugger& CBigBugger::operator=(CBigBugger&& aOther)
{
	mElementCount = aOther.mElementCount;
	mpBigCollection.swap(aOther.mpBigCollection);

	return *this;
}

CBigBugger::~CBigBugger()
{
}

auto CBigBugger::Vec() -> std::vector<int>
{
	return std::vector<int>(&mpBigCollection[0], &mpBigCollection[mElementCount]);
}

auto MovedBugger() -> CBigBugger
{
	return { 53,654,63,345,65,34,5,654,3,3456,323,56,654,2,45 };
}

auto ClassInSession() -> void
{
	CBigBugger aBuggerOne{12,332,64,46,65,75443,434,45};
	CBigBugger aBuggerTwo = MovedBugger();

	std::cout << "Bugger: ";
	for(auto aVal : aBuggerTwo.Vec())
	{
		std::cout << aVal << R"*(\())*";
	}

	std::cout << std::endl;
}
