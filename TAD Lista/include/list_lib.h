#ifndef _LIST_LIBRARY_
#define _LIST_LIBRARY_

#include <memory>

using size_type = long int;

/**
 * Classe de um vetor dinâmico. [Descrição]
 */

template < typename T >
class Vector
{
	public:
		/*
		class const_iterator { 
			public:
				const_iterator(Node* x) : current(x) {}
				const T & operator* ( ) const;
				const_iterator & operator++ (); //++it
				const_iterator operator++ (int); //it++
				const_iterator & operator-- ();  //--it
				const_iterator operator-- (int); //it--
				bool operator== (const const_iterator & rhs) const;
				bool operator!= (const const_iterator & rhs) const;
				
			protected:
				Node *current;
				friend class List<T>;
		};
		
		class iterator : public const_iterator { 
			public:
				iterator() : const_iterator() {  }
				const T & operator* ( ) const;
				T & operator* ();
				
				iterator & operator++ (); //++it
				iterator operator++ (int); //it++
				iterator & operator-- ();  //--it
				iterator operator-- (int); //it--
				
			protected:
				iterator( Node *p) : const_iterator(p);
				friend class List<T>;			
		};
		*/

		/** Construtor da classe*/
		Vector( size_type mi_size = 1 );
		/** Destrutor da classe*/
		~Vector(){ /* empty */}
		
		/* COMMON METHODS */
		
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
		
		/* OPERATIONS EXCLUSIVE TO DINAMIC ARRAY */
		
		/** Retorna o valor referente a posição idx (sem verificar limites) */
		T & operator[]( size_type idx);
		/** Retorna o valor referente a posição idx (verificando limites) */
		T & at ( size_type idx );
		/** Retorna a capacidade máxima de armazenamento */
		size_type capacity() const;
		/** MOdifica a capacidade de armazenamento para new_capacity */
		void reserve( size_type new_capacity );
		
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
		
		/* COMMON METHODS */
		bool empty();
		size_type size() const;
		void push_back( const T & x );
		void pop_back();
		void clear();
		const T & back() const;
		const T & front() const;
		void assign( const T & x ); 
		
		/* OPERATIONS EXCLUSIVE TO LINKED LISTS */
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

#include "vector.inl"
#include "forward_list.inl"
#include "list.inl"
#endif