/*! 
 *  @file list_lib.h
 *  @brief Arquivo com a biblioteca contendo todas as classes da TAD lista.
 *
 */
#ifndef _LIST_LIBRARY_
#define _LIST_LIBRARY_

#include <memory>

using size_type = long int;

/*!
 *	@brief Classe que implementa a TAD lista com array dinâmico.
 */
template < typename T >
class Vector
{
	public:

		/*!
		 *  @brief Construtor da classe Vector.
		 *  @param mi_size A capacidade do array dinâmico.
		 */
		Vector( size_type mi_size = 1 );

		~Vector(){ /* empty */} // Destrutor da classe.

		/* MÉTODOS COMUNS */
		
		/*!
		 *  @brief Retorna o tamanho do array.
		 *  @return Tamanho do array.
		 */		
		size_type size() const;

		/*!
		 *  @brief Apaga todos os elementos do array.
		 */
		void clear();

		/*!
		 *  @brief Checa se o arranjo está vazio.
		 *  @return True se o arranjo estiver vazio, False caso contrário.
		 */
		bool empty();

		/*!
		 *  @brief Adiciona um elemento no fim do arranjo.
		 *  @param x O elemento a ser adicionado.
		 */
		void push_back( const T & x );
		
		/*!
		 *  @brief Remove o elemento do fim do arranjo.
		 */
		void pop_back();

		/*!
		 *  @brief Retorna o valor do último elemento do arranjo.
		 *  @return O último elemento do arranjo.
		 */
		const T & back() const;

		/*!
		 *  @brief Retorna o valor do primeiro elemento do arranjo.
		 *  @return O primeiro elemento do arranjo.
		 */
		const T & front() const;

		/*!
		 *  @brief Atribui um valor a todas as posições do arranjo.
		 */
		void assign( const T & x );
		
		/*!
		 *	@brief Classe de implementação do iterador constante.
		 */
		class const_iterator;

		/*!
		 *	@brief Classe de implementação do iterador.
		 */
		class iterator;
		
		/*!
		 *	@brief Iterador para o começo do arranjo.
		 *	@return Iterador para o primeiro elemento do arranjo.
		 */
		iterator begin();

		/*!
		 *	@brief Iterador constante para o começo do arranjo.
		 *	@return Iterador constante para o primeiro elemento do arranjo.
		 */
		const_iterator cbegin() const;

		/*!
		 *	@brief Iterador para indicar o fim do arranjo.
		 *	@return Iterador para a posição de memória após o último elemento do arranjo.
		 */
		iterator end();

		/*!
		 *	@brief Iterador constante para indicar o fim do arranjo.
		 *	@return Iterador constante a para posição de memória após o último elemento do arranjo.
		 */
		const_iterator cend() const;
		
		/* OPERAÇÕES EXCLUSIVAS DO VECTOR */
		
		/*!
		 *	@brief Sobrecarga do operador[].
		 *	@param idx Índice do arranjo que se deseja acessar.
		 *	@return Elemento do arranjo que ocupa o índice.
		 */
		T & operator[]( size_type idx);

		/*!
		 *	@brief Retorna um elemento em uma posição do arranjo.
		 *	@param idx Índice do arranjo que se deseja acessar.
		 *	@return Elemento do arranjo que ocupa o índice.
		 */
		T & at ( size_type idx );

		/*!
		 *	@brief Retorna a capacidade do arranjo.
		 *	@return Valor da capacidade do arranjo.
		 */
		size_type capacity() const;

		/*!
		 *	@brief Reserva um espaço na memória para o arranjo.
		 *	@param new_capacity Nova capacidade do arranjo.
		 */
		void reserve( size_type new_capacity );

	private:
		
		size_type v_size;
		size_type v_capacity;
		std::unique_ptr< T[] > mi_vector;		
};

/*!
 *	@brief Classe que implementa a TAD lista com lista simplesmente encadeada.
 */
template < typename T >
class Forward_List
{
	public:

		/*!
		 *  @brief Construtor da classe Forward_List.
		 */
		Forward_List();

		~Forward_List(); // Destrutor da classe.
		
		/* MÉTODOS COMUNS */

		/*!
		 *  @brief Checa se a lista está vazia.
		 *  @return True se a lista estiver vazia, False caso contrário.
		 */
		bool empty();

		/*!
		 *  @brief Retorna o tamanho da lista.
		 *  @return Tamanho da lista.
		 */
		size_type size() const;

		/*!
		 *  @brief Adiciona um elemento no fim da lista.
		 *  @param x O elemento a ser adicionado.
		 */
		void push_back( const T & x );

		/*!
		 *  @brief Remove o elemento do fim da lista.
		 */
		void pop_back();

		/*!
		 *  @brief Apaga todos os elementos da lista.
		 */
		void clear();

		/*!
		 *  @brief Retorna o valor do último elemento da lista.
		 *  @return O último elemento da lista.
		 */
		const T & back() const;

		/*!
		 *  @brief Retorna o valor do primeiro elemento da lista.
		 *  @return O primeiro elemento da lista.
		 */
		const T & front() const;

		/*!
		 *  @brief Atribui um valor a todas as posições da lista.
		 */
		void assign( const T & x ); 
		
		/*!
		 *	@brief Classe de implementação do iterador constante.
		 */
		class const_iterator;

		/*!
		 *	@brief Classe de implementação do iterador.
		 */
		class iterator;
		
		/*!
		 *	@brief Iterador para o começo da lista.
		 *	@return Iterador para o primeiro elemento da lista.
		 */
		iterator begin();

		/*!
		 *	@brief Iterador constante para o começo da lista.
		 *	@return Iterador constante para o primeiro elemento da lista.
		 */
		const_iterator cbegin() const;

		/*!
		 *	@brief Iterador para indicar o fim da lista.
		 *	@return Iterador para a posição de memória após o último elemento da lista.
		 */
		iterator end();

		/*!
		 *	@brief Iterador constante para indicar o fim da lista.
		 *	@return Iterador constante a para posição de memória após o último elemento da lista.
		 */
		const_iterator cend() const;
		
		/*!
		 *	@brief Insere elemento na lista antes da posição apontada por um iterador.
		 *	@param pos Iterador que aponta a uma posição na lista.
		 *	@param x elemento a ser inserido.
		 *	@return Iterador para a posição onde o elemento foi inserido.
		 */
		iterator insert_after( const_iterator pos, const T & x );

		/*!
		 *	@brief Remove um elemento da lista na posição apontada por um iterador.
		 *	@param pos Iterador que aponta a uma posição na lista.
		 *	@return Iterador para o elemento após o iterador passado.
		 */
		iterator erase_after( const_iterator pos );

		/*!
		 *	@brief Remove elementos da lista em um intervalo delimitado por iteradores.
		 *	@param first Iterador para o início do intervalo.
		 *	@param last Iterador para uma posição após o último elemento a ser removido.
		 */
		iterator erase_after( const_iterator first, const_iterator last );

		/*!
		 *	@brief Insere na lista os elemento de uma lista dada antes da posição apontada por um iterador.
		 *	@param ilist Lista com os elementos as serem inseridos.
		 *	@return Iterador para a posição onde o último elemento foi inserido.
		 */
		iterator insert_after( const_iterator pos, std::initializer_list<T> ilist );

		/*!
		 *	@brief Busca um elemento na lista.
		 *	@param x Elemento a ser procurado.
		 *	@return Iterador para a posição do elemento, ou iterador end() caso o elemento não seja encontrado.
		 */
		const_iterator find ( const T & x ) const;

		/*!
		 *	@brief Substitui elementos da lista pelos elementos de uma lista passada.
		 *	@param ilist Lista contendo os elementos.
		 */
		void assign ( std::initializer_list <T > ilist );
		
		/* OPERAÇÕES EXCLUSIVAS DE LISTAS ENCADEADAS */

		/*!
		 *  @brief Adiciona um elemento no início da lista.
		 *  @param x O elemento a ser adicionado.
		 */
		void push_front( const T & x );

		/*!
		 *  @brief Remove o elemento do início da lista.
		 */
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

/*!
 *	@brief Classe que implementa a TAD lista com lista duplamente encadeada.
 */
template < typename T >
class List
{
	public:

		/*!
		 *  @brief Construtor da classe List.
		 */
		List();
		~List(); // Destrutor da classe.
		
		/* MÉTODOS COMUNS */

		/*!
		 *  @brief Retorna o tamanho da lista.
		 *  @return Tamanho da lista.
		 */
		size_type size() const;

		/*!
		 *  @brief Apaga todos os elementos da lista.
		 */
		void clear();

		/*!
		 *  @brief Checa se a lista está vazia.
		 *  @return True se a lista estiver vazia, False caso contrário.
		 */
		bool empty();

		/*!
		 *  @brief Adiciona um elemento no fim da lista.
		 *  @param x O elemento a ser adicionado.
		 */
		void push_back( const T & x );

		/*!
		 *  @brief Remove o elemento do fim da lista.
		 */
		void pop_back();

		/*!
		 *  @brief Retorna o valor do último elemento da lista.
		 *  @return O último elemento da lista.
		 */
		const T & back() const;

		/*!
		 *  @brief Retorna o valor do primeiro elemento da lista.
		 *  @return O primeiro elemento da lista.
		 */
		const T & front() const;

		/*!
		 *  @brief Atribui um valor a todas as posições da lista.
		 */
		void assign( const T & x );

		/*!
		 *	@brief Classe de implementação do iterador constante.
		 */
		class const_iterator;

		/*!
		 *	@brief Classe de implementação do iterador.
		 */
		class iterator;
		
		/*!
		 *	@brief Iterador para o começo da lista.
		 *	@return Iterador para o primeiro elemento da lista.
		 */
		iterator begin();

		/*!
		 *	@brief Iterador constante para o começo da lista.
		 *	@return Iterador constante para o primeiro elemento da lista.
		 */
		const_iterator cbegin() const;

		/*!
		 *	@brief Iterador para indicar o fim da lista.
		 *	@return Iterador para a posição de memória após o último elemento da lista.
		 */
		iterator end();

		/*!
		 *	@brief Iterador constante para indicar o fim da lista.
		 *	@return Iterador constante a para posição de memória após o último elemento da lista.
		 */
		const_iterator cend() const;
		
		/*!
		 *	@brief Insere elemento na lista antes da posição apontada por um iterador.
		 *	@param pos Iterador que aponta a uma posição na lista.
		 *	@param x elemento a ser inserido.
		 *	@return Iterador para a posição onde o elemento foi inserido.
		 */
		iterator insert_after(const_iterator pos, const T & x);

		/*!
		 *	@brief Remove um elemento da lista na posição apontada por um iterador.
		 *	@param pos Iterador que aponta a uma posição na lista.
		 *	@return Iterador para o elemento após o iterador passado.
		 */
		iterator erase_after( const_iterator pos);

		/*!
		 *	@brief Remove elementos da lista em um intervalo delimitado por iteradores.
		 *	@param first Iterador para o início do intervalo.
		 *	@param last Iterador para uma posição após o último elemento a ser removido.
		 */
		iterator erase_after( const_iterator first, const_iterator last );

		/*!
		 *	@brief Insere na lista os elemento de uma lista dada antes da posição apontada por um iterador.
		 *	@param ilist Lista com os elementos as serem inseridos.
		 *	@return Iterador para a posição onde o último elemento foi inserido.
		 */
		iterator insert_after( const_iterator pos, std::initializer_list<T> ilist );

		/*!
		 *	@brief Busca um elemento na lista.
		 *	@param x Elemento a ser procurado.
		 *	@return Iterador para a posição do elemento, ou iterador end() caso o elemento não seja encontrado.
		 */
		const_iterator find (const T & x) const;

		/*!
		 *	@brief Substitui elementos da lista pelos elementos de uma lista passada.
		 *	@param ilist Lista contendo os elementos.
		 */
		void assign ( std::initializer_list <T> ilist );
		

		/* OPERAÇÕES EXCLUSIVAS DE LISTAS ENCADEADAS */

		/*!
		 *  @brief Adiciona um elemento no início da lista.
		 *  @param x O elemento a ser adicionado.
		 */
		void push_front( const T & x );

		/*!
		 *  @brief Remove o elemento do início da lista.
		 */
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