#include <iostream>
#include <memory>

int main() {
	
	int * ptrRegular = new int(5);
	std::unique_ptr<int> ptrSmart(new int(10));

	std::cout << "ptrRegular: " << *ptrRegular;
	std::cout << ", ptrSmart: " << *ptrSmart << std::endl;

	delete ptrRegular; // É preciso liberar a memória alocada

	return 0;
}