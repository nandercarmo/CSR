#include <iostream>
#include <memory>

int main() {

	std::shared_ptr<int> ptr1(new int());
	std::shared_ptr<int> ptr2 = ptr1;

	*ptr1 = 100;

	std::cout << "ptr1: " << *ptr1;
	std::cout << ", ptr2: " << *ptr2 << std::endl;

	return 0;
}