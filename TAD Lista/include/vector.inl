/*! 
 *  @file vector.inl
 *  @brief Arquivo com implementação dos métodos da classe Vector.
 *
 */

#include "list_lib.h"
#include <stdexcept>

using namespace std;

//Construtor
template < typename T >
Vector<T>::Vector( size_type mi_size ):
    v_size(0),
    v_capacity( mi_size ),
    mi_vector( new T[mi_size] )
{ /* empty */ }

//Função que retorna o tamanho
template < typename T >
size_type Vector<T>::size() const
{
    return v_size;
}

//Função para apagar o vetor
template < typename T >
void Vector<T>::clear()
{
    while (v_size > 0)
        mi_vector[--v_size].~T();
}

//FUnção que verifica se o vetor é vazio
template < typename T >
bool Vector<T>::empty() 
{
    return (v_size == 0);
}

//Adiciona um elemento ao final do vetor
template < typename T >
void Vector<T>::push_back( const T & x ) 
{
    if (v_size >= v_capacity)
        reserve( v_capacity * 2 );
    
    mi_vector[v_size++] = x;
}

//Remove um elemento do fim do vetor
template < typename T >
void Vector<T>::pop_back()
{
    if ( not empty() )
        mi_vector[--v_size].~T();
}

//Retorna o ultimo elemento do vetor
template < typename T >
const T & Vector<T>::back() const
{
    return mi_vector[v_size - 1];
    // Assim como na biblioteca padrão, o comportamento da função é indefinido quando o vector está vazio.
}

//Retorna o primeiro elemento do vetor
template < typename T >
const T & Vector<T>::front() const 
{
    return mi_vector[0];
}

template < typename T >
void Vector<T>::assign( const T & x )
{
    for (size_type i = 0; i < v_size; i++)
    {
        mi_vector[i] = x;
    }
}

//  OPERAÇÕES EXCLUSIVAS DO VECTOR

template < typename T >
T & Vector<T>::operator[]( size_type idx ) 
{
    return mi_vector[idx];
}


template < typename T >
T & Vector<T>::at ( size_type idx ) 
{
    if ( idx < v_size and idx >= 0 )
    {
        return mi_vector[idx];
    }
    throw std::out_of_range("Índice inválido.");
}

template < typename T >
size_type Vector<T>::capacity() const
{
    return v_capacity;
}

template < typename T >
void Vector<T>::reserve( size_type new_capacity )
{
    
    if (new_capacity > v_capacity) 
    {
        std::unique_ptr<T[]> aux_ptr(new T[ new_capacity ]);

    	for (size_type i = 0; i < v_size; ++i)
    		aux_ptr[i] = mi_vector[i];
    
    	mi_vector = std::move(aux_ptr);
    
    	v_capacity = new_capacity;
    }
}


// IMPLEMENTAÇÃO DOS ITERADORES

template < typename T >
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return const_iterator( mi_vector.get() );
}

template < typename T >
typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return const_iterator( mi_vector.get() + v_size );
    
}

template < typename T >
typename Vector<T>::iterator Vector<T>::begin()
{
    return iterator( mi_vector.get() );
}

template < typename T >
typename Vector<T>::iterator Vector<T>::end()
{
    return iterator( mi_vector.get() + v_size );
}
