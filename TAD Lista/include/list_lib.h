#ifndef _LIST_LIBRARY_
#define _LIST_LIBRARY_

#include <memory>

using size_type = long int;

/*!
 */

template < typename T >
class Vector
{
	public:
	
		/** Construtor da classe*/
		Vector( size_type mi_size = 1 );
		/** Destrutor da classe*/
		~Vector(){ /* empty */}
		
		/* MÉTODOS COMUNS */
		
		/** Retorna o números de elementos do vetor*/
		size_type size() const;
		/** Remove todos os elementos*/
		void clear();
		/** Verifica se o vetor está vazio*/
		bool empty();
		/** Insere um valor x no final do vetor*/
		void push_back( const T & x );
		/** Deleta o ultimo elemento do vetor*/
		void pop_back();
		/** Retorna o ultimo elemento do vetor*/
		const T & back() const;
		/** Retorn o primeiro elemento do vetor*/
		const T & front() const;
		/** Subsitui todos os valores do vetor por um determinado x */
		void assign( const T & x );
		
		
		/* OPERAÇÕES EXCLUSIVAS DO VECTOR */
		
		/** Retorna o valor referente a posição idx (sem verificar limites) */
		T & operator[]( size_type idx);
		/** Retorna o valor referente a posição idx (verificando limites) */
		T & at ( size_type idx );
		/** Retorna a capacidade máxima de armazenamento */
		size_type capacity() const;
		/** MOdifica a capacidade de armazenamento para new_capacity */
		void reserve( size_type new_capacity );
		
		class const_iterator;
		class iterator;
		
		
		iterator begin();
		const_iterator cbegin() const;
		iterator end();
		const_iterator cend() const;
		
	private:
		
		size_type v_size;
		size_type v_capacity;
		std::unique_ptr< T[] > mi_vector;
		
};

template < typename T >
class Forward_List
{
	public:
	
		Forward_List();
		~Forward_List();
		
		/* MÉTODOS COMUNS */
		bool empty();
		size_type size() const;
		void push_back( const T & x );
		void pop_back();
		void clear();
		const T & back() const;
		const T & front() const;
		void assign( const T & x ); 
		
		class const_iterator;
		class iterator;
		
		iterator begin();
		const_iterator cbegin() const;
		iterator end();
		const_iterator cend() const;
		
		iterator insert_after(const_iterator pos, const T & x);
		iterator erase_after( const_iterator pos);
		iterator erase_after( const_iterator first, const_iterator last );
		iterator insert_after( const_iterator pos, std::initializer_list<T> ilist );
		const_iterator find (const T & x) const;
		void assign ( std::initializer_list <T > ilist );
		
		/* OPERAÇÕES EXCLUSIVAS DE LISTAS ENCADEADAS */
		void push_front( const T & x );
		void pop_front();
		
	private:
		struct Node 
		{
			T data;
			Node *next;
			Node ( const T & d = T ( ) , Node * p = nullptr , Node * n = nullptr ) : 
				data(d),
				next(n)
			{/* empty */}
		};
		
		size_type m_size;
		Node * m_head;
		Node * m_tail;
};

template < typename T >
class List
{
	public:
	
		List();
		~List();
		
		/* MÉTODOS COMUNS */
		size_type size() const;
		void clear();
		bool empty();
		void push_back( const T & x );
		void pop_back();
		const T & back() const;
		const T & front() const;
		void assign( const T & x );
		
		class const_iterator;
		class iterator;
		
		iterator begin();
		const_iterator cbegin() const;
		iterator end();
		const_iterator cend() const;
		
	
		iterator insert_after(const_iterator pos, const T & x);
		iterator erase_after( const_iterator pos);
		iterator erase_after( const_iterator first, const_iterator last );
		iterator insert_after( const_iterator pos, std::initializer_list<T> ilist );
		const_iterator find (const T & x) const;
		void assign ( std::initializer_list <T > ilist );
		
		/* OPERAÇÕES EXCLUSIVAS DE LISTAS ENCADEADAS */
		void push_front( const T & x );
		void pop_front();
		
	private:
		struct Node 
		{
			T data;
			Node *next;
			Node *prev;
			Node ( const T & d = T ( ) , Node * p = nullptr , Node * n = nullptr,  Node * m = nullptr) : 
				data(d),
				next(n), 
				prev(m)
			{/* empty */}
		};
		
		size_type m_size;
		Node * m_head;
		Node * m_tail;
};


// |------------------------------------------------------------------|
// |------------------ IMPLEMENTAÇÃO DOS ITERADORES ------------------|
// |------------------------------------------------------------------|



// |--------------------- ITERADORES DO VECTOR -----------------------|

template < typename T >
class Vector<T>::const_iterator 
{ 
	public:
		const_iterator( T * x = nullptr ) : current(x) {  }
		const T & operator* ( ) const { return *current; }
		
		
		const_iterator & operator++ () { current++; return *this;} //++it
		const_iterator operator++ (int) {const_iterator aux(current); current++; return aux;} //it++
		const_iterator & operator-- () { current--; return *this;}  //--it
		const_iterator operator-- (int) {const_iterator aux(current); current--; return aux;} //it--
		bool operator== (const const_iterator & rhs) const {return current == rhs.current;}
		bool operator!= (const const_iterator & rhs) const {return current != rhs.current;}
		
	protected:
		T * current;
		friend class Vector<T>;
};
		
template < typename T >
class Vector<T>::iterator : public Vector<T>::const_iterator 
{ 
	public:
		iterator( T * x = nullptr ) : const_iterator(x) {  };
		T & operator* () { return *const_iterator::current; } 
};

// =================================================================

// |------------------ ITERADORES DO FORWARD LIST ------------------|

template < typename T >
class Forward_List<T>::const_iterator 
{ 
	public:
		const_iterator( Node * x = nullptr ) : current(x) {  }
		const T & operator* ( ) const { return current->data; }
		
		
		const_iterator & operator++ () { current = current->next; return *this;} //++it
		const_iterator operator++ (int) { const_iterator aux(current); current = current->next; return aux;} //it++
		bool operator== (const const_iterator & rhs) const {return current->data == rhs.current->data;}
		bool operator!= (const const_iterator & rhs) const {return current->data != rhs.current->data;}
		
	protected:
		Node * current;
		friend class Forward_List<T>;
};
		
template < typename T >
class Forward_List<T>::iterator : public Forward_List<T>::const_iterator 
{ 
	public:
		iterator( Node * x = nullptr ) : const_iterator(x) {  }
		T & operator* () { return const_iterator::current->data; } 
};

// ==================================================================

// |----------------------- ITERADORES DO LIST ---------------------|

template < typename T >
class List<T>::const_iterator 
{ 
	public:
		const_iterator( Node * x = nullptr ) : current(x) {  }
		const T & operator* ( ) const { return current->data; }
		
		
		const_iterator & operator++ () { current = current->next; return *this;} //++it
		const_iterator operator++ (int) { const_iterator aux(current); current = current->next; return aux;} //it++
		const_iterator & operator-- () { current = current->prev; return *this;}  //--it
		const_iterator operator-- (int) { const_iterator aux(current); current = current->prev; return aux;} //it--
		bool operator== (const const_iterator & rhs) const {return current->data == rhs.current->data;}
		bool operator!= (const const_iterator & rhs) const {return current->data != rhs.current->data;}
		
	protected:
		Node * current;
		friend class List<T>;
};
		
template < typename T >
class List<T>::iterator : public List<T>::const_iterator 
{ 
	public:
		iterator( Node * x = nullptr ) : const_iterator(x) {  }
		T & operator* () { return const_iterator::current->data; } 
};

// ==================================================================

#include "vector.inl"
#include "forward_list.inl"
#include "list.inl"

#endif