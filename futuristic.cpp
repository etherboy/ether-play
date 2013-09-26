#include "futuristic.h"
#include <thread>
#include <future>
#include <iostream>

int Spinner(double aOne, double aTwo)
{
	for(int i = 0; i < 20; ++i)
	{
		std::cout << "thread: " << std::this_thread::get_id() << " " << aOne << std::endl;
		aOne += aTwo;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	return static_cast<int>(aOne);
}

void futurist()
{
	auto aFuture = std::async(std::launch::async, Spinner, 5.0, 6.0);

	while(aFuture.wait_for(std::chrono::seconds(0)) == std::future_status::timeout)
	{
		std::cout << "waiting" << std::endl;
	}

	std::cout << "Future: " << aFuture.get() << std::endl;
}
