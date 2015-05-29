#include <iostream>
#include <thread>

void hello()
{
	std::cout << "Hello Threaded World\n";
}

int main()
{
	std::thread t(hello);
	std::cout<< "Hello Main World\n";
	t.join();
	
	return 0;
}
