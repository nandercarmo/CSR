#include <iostream>

int main() {

	int var1 = 1;

	int * ptr = &var1;
	int & ref = var1;

	// Valores iniciais
	std::cout << "ptr: " << &ptr;
	std::cout << ", ref: " << &ref;
	std::cout << ", var1: " << &var1 << std::endl;

	return 0;
}