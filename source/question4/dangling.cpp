#include <iostream>
#include <memory>

int main() {
	
	int * ptrRegular = new int(5);
	
	{
		std::shared_ptr<int> ptrSmart;
		ptrSmart.reset(ptrRegular);

		std::cout << "ptrRegular: " << *ptrRegular;
		std::cout << ", ptrSmart: " << *ptrSmart << std::endl;
	}

	delete ptrRegular; // Tenta liberar um espaço de memória que já foi liberado

	return 0;
}