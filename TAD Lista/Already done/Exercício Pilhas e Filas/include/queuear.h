#ifndef QUEUEAR_H
#define QUEUEAR_H

#include "AbsQueue.h"
#include <stdexcept>
template < typename Object >
class QueueAr : public AbsQueue<Object>
{
	public:
		QueueAr( int _size = 10 );
		~QueueAr(){ delete [] myQueue; }

		void enqueue( const Object & x );
		Object dequeue();
		Object getFront() const;

		bool isEmpty() const;
		void makeEmpty();
		

	private:

		int front; //A posição na qual o próximo número será inserido.
		int rear;
		int capacity;
		Object *myQueue;

		void resize( int );

	friend std::ostream & operator<< ( std::ostream & _os, const QueueAr & _ms )
	{
		
		int num_elements;

		if ( _ms.front == -1 )
			num_elements = 0;
		else
			num_elements = ( _ms.rear + _ms.capacity - _ms.front ) % _ms.capacity + 1;

		int k = _ms.front;

		_os << "[ ";

		for ( int i(0); i < num_elements ; ++i ){
			_os << _ms.myQueue[k] << " ";
			k = (k + 1) % _ms.capacity;
		}

		_os << "]\n\n";
		
		return _os;
	}
};

template < typename Object >
QueueAr<Object>::QueueAr( int _size ) :
	front(-1),
	rear(-1),
	capacity( _size )
{
	myQueue = new Object[ _size ];
}

template < typename Object >
void QueueAr<Object>::resize( int newLength )
{
	Object * Q = new Object[newLength];

	if ( front < rear )
	{
		for (int i = front; i <= rear; ++i)
			Q[i] = myQueue[i];
	}
	
	else
	{
		for (int i = 0; i <= rear; ++i)
			Q[i] = myQueue[i];

		for (int i = front; i < capacity; ++i)
			Q[i + capacity] = myQueue[i];

		front += capacity;
	}

	delete [] myQueue;

	myQueue = Q;

	capacity = newLength;
}

template < typename Object >
bool QueueAr<Object>::isEmpty() const
{
	return ( front == -1 and rear == -1 );
}

template < typename Object >
void QueueAr<Object>::makeEmpty()
{
	front = -1;
	rear = -1;
}

template < typename Object >
void QueueAr<Object>::enqueue( const Object & x )
{

	if ( (rear + 1) % capacity == front or capacity == 1 )
	{
		resize( 2*capacity );
	}

	if ( isEmpty() )
	{
		front++;
		rear++;
		myQueue[rear] = x;
	}
	else
	{
		rear = (rear + 1) % capacity;
		myQueue[rear] = x;
	}

}

template < typename Object >
Object QueueAr<Object>::dequeue()
{
	if ( isEmpty() )
	{
		throw std::length_error("Underflow!");
	}

	Object elm_dequeued = myQueue[front];

	if ( front == rear )
		makeEmpty();
	else
		front = (front + 1) % capacity;

	return elm_dequeued;
}

template < typename Object >
Object QueueAr<Object>::getFront() const
{
	if ( isEmpty() )
	{
		throw std::length_error("Fila vazia!");
	}

	return myQueue[front];
}

#endif