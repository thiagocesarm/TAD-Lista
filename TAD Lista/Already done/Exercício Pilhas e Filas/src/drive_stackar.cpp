// g++ -Wall -std=c++11 -I include/ src/drive_stackar.cpp -o bin/stackar

#include <iostream>
#include "stackar.h"

int main()
{
	StackAr<int> my_stack(2);

	if( my_stack.isEmpty() )
		std::cout << "Pilha vazia!\n\n";
	
	std::cout << "my_stack: \n" << my_stack;

	my_stack.push(8);
	my_stack.push(16);
	my_stack.push(32);
	my_stack.push(64);
	my_stack.push(128);


	std::cout << "my_stack depois de pushs: \n" << my_stack;

	std::cout << "Elemento do topo: " << my_stack.top() << "\n\n";

	std::cout << "Retirando elemento " << my_stack.pop() << " do topo da pilha.\n";
	std::cout << "Retirando elemento " << my_stack.pop() << " do topo da pilha.\n";

	std::cout << "my_stack depois de 2 pops: \n" << my_stack;
	std::cout << "Elemento do topo: " << my_stack.top() << "\n\n";

	my_stack.push(256);
	my_stack.push(512);
	my_stack.push(1024);
	my_stack.push(2048);
	my_stack.push(4096);
	my_stack.push(8192);

	std::cout << "my_stack depois de pushs: \n" << my_stack;
	std::cout << "Elemento do topo: " << my_stack.top() << "\n\n";

	std::cout << "Retirando elemento " << my_stack.pop() << " do topo da pilha.\n";
	std::cout << "Retirando elemento " << my_stack.pop() << " do topo da pilha.\n";
	std::cout << "Retirando elemento " << my_stack.pop() << " do topo da pilha.\n";
	std::cout << "Retirando elemento " << my_stack.pop() << " do topo da pilha.\n";

	std::cout << "my_stack depois de 4 pops: \n" << my_stack;
	std::cout << "Elemento do topo: " << my_stack.top() << "\n\n";

	my_stack.makeEmpty();
	std::cout << "my_stack depois de makeEmpty: \n" << my_stack;

	if( my_stack.isEmpty() )
		std::cout << "Pilha agora está vazia!\n";

	return EXIT_SUCCESS;
}