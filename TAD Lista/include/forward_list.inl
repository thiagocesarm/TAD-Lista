#include "list_lib.h"
#include <stdexcept>

using namespace std;

template < typename T >
Forward_List<T>::Forward_List();

Forward_List<T>::~Forward_List();
		
		/* COMMON METHODS */
		size_type size() const;
		void clear();
		bool empty();
		void push_back( const T & x );
		void pop_back();
		const T & back() const;
		const T & front() const;
		void assign( const T & x );
		
		/* OPERATIONS EXCLUSIVE TO LINKED LISTS */
		void push_front( const T & x );
		void pop_front();