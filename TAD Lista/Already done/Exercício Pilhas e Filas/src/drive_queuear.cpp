// g++ -Wall -std=c++11 -I include/ src/drive_queuear.cpp -o bin/queuear

#include <iostream>
#include "queuear.h"

int main()
{
	QueueAr<int> my_queue(5);

	if( my_queue.isEmpty() )
		std::cout << "Fila vazia!\n\n";

	std::cout << "Fila: \n" << my_queue;

	my_queue.enqueue(10);
	my_queue.enqueue(20);
	my_queue.enqueue(30);
	my_queue.enqueue(40);
	my_queue.enqueue(50);

	std::cout << "Fila: \n" << my_queue;
	std::cout << "Elemento da frente: " << my_queue.getFront() << "\n\n";


	my_queue.dequeue();
	my_queue.dequeue();
	my_queue.dequeue();
	my_queue.dequeue();

	std::cout << "Fila: \n" << my_queue;
	std::cout << "Elemento da frente: " << my_queue.getFront() << "\n\n";

	my_queue.enqueue(60);
	my_queue.enqueue(70);
	my_queue.enqueue(80);
	my_queue.enqueue(90);

	std::cout << "Fila: \n" << my_queue;
	std::cout << "Elemento da frente: " << my_queue.getFront() << "\n\n";


	my_queue.enqueue(100);
	std::cout << "Fila: \n" << my_queue;
	std::cout << "Elemento da frente: " << my_queue.getFront() << "\n\n";

	my_queue.makeEmpty();
	std::cout << "my_queue depois de makeEmpty: \n" << my_queue;

	if( my_queue.isEmpty() )
		std::cout << "Fila agora está vazia!\n";

	return EXIT_SUCCESS;
}