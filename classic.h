#include <initializer_list>
#include <vector>
#include <memory>

class CBigBugger
{
public:
	CBigBugger();
	CBigBugger(const CBigBugger&) = default;
	CBigBugger(std::initializer_list<int> aList);
	CBigBugger(CBigBugger&& aOther);
	CBigBugger& operator=(CBigBugger&& aOther);
	~CBigBugger();

	auto Vec() -> std::vector<int>;

private:
	size_t mElementCount = 0; 
	std::unique_ptr<int[]> mpBigCollection;
};

auto ClassInSession() -> void;
