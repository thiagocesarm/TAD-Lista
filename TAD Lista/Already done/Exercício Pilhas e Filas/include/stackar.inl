#include <stdexcept>
#include "stackar.h"

template < typename Object >
StackAr<Object>::StackAr( int _size ) : 
	topo( 0 ),
	capacity( _size )
{
	myStack = new Object[ _size ];
}

template < typename Object >
void StackAr<Object>::resize( int newLength )
{
	Object *P = new Object[ newLength ];

	for (int i = 0; i <= topo; ++i)
		P[i] = myStack[i];

	delete [] myStack;

	myStack = P;

	capacity = newLength;	
}

template < typename Object >
bool StackAr<Object>::isEmpty() const
{
	return (topo == 0);
}

template < typename Object >
void StackAr<Object>::makeEmpty()
{
	topo = 0;
}

template < typename Object >
void StackAr<Object>::push( const Object & x )
{
	if ( topo == capacity )
		resize( 2 * capacity );

	myStack[ topo++ ] = x;
}

template < typename Object >
Object StackAr<Object>::pop()
{
	if ( isEmpty() )
		throw std::length_error("Underflow!");

	return myStack[--topo];
}

template < typename Object >
Object StackAr<Object>::top()
{
	return myStack[topo - 1];
}