#ifndef STACKAR_H
#define STACKAR_H

#include "AbsStack.h"

template < typename Object >
class StackAr : public AbsStack<Object>
{
	public:
		StackAr( int _size = 10 );
		~StackAr(){ delete [] myStack; }
		void push( const Object & x );
		Object pop();
		Object top();

		bool isEmpty() const;
		void makeEmpty();

	private:

		int topo; //A posição na qual o próximo número será inserido.
		int capacity;
		Object *myStack;

		void resize( int );

	friend std::ostream & operator<< ( std::ostream & _os, const StackAr & _ms )
	{
		_os << "[ ";
		for ( int i(0); i < _ms.topo; ++i )
			_os << _ms.myStack[i] << " ";
		_os << "]\n\n";
		_os << "Topo da pilha: " << _ms.topo << "\n";
		
		return _os;
	}
};

#include "stackar.inl"

#endif