#include <iostream>

int main() {

	int var1 = 1;
	int var2 = 2;

	int * ptr = &var1;
	int & ref = var1;

	// Valores iniciais
	std::cout << "ptr: " << *ptr;
	std::cout << ", ref: " << ref;
	std::cout << ", var1: " << var1;
	std::cout << ", var2: " << var2 << std::endl;

	ptr = &var2;

	// É possível reatribuir o valor apontado por um ponteiro
	std::cout << "ptr: " << *ptr;
	std::cout << ", ref: " << ref;
	std::cout << ", var1: " << var1;
	std::cout << ", var2: " << var2 << std::endl;

	ref = var2;

	// Ao tentar reatribuir uma referência, a variável referenciada por ela é alterada também
	// Não é possível reatribuir uma referência
	std::cout << "ptr: " << *ptr;
	std::cout << ", ref: " << ref;
	std::cout << ", var1: " << var1;
	std::cout << ", var2: " << var2 << std::endl;

	return 0;
}