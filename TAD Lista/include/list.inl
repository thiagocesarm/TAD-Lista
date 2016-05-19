#include "list_lib.h"
#include <stdexcept>

using namespace std;

template < typename T >
List<T>::List() :
    m_size(0),
    m_head(new Node),
    m_tail(new Node)
{
    m_head->next = m_tail;
    m_tail->prev =  m_head;
}

template < typename T >
List<T>::~List()
{
    clear();
    delete m_head;
    delete m_tail;
}

template < typename T >
bool List<T>::empty() 
{
    return ( m_head->next == m_tail and m_tail->prev ==  m_head);
}

template < typename T >
size_type List<T>::size() const 
{
    return m_size;
}

template < typename T >
void List<T>::push_back( const T & x )
{
    Node * ultimo = new Node;
    
    ultimo->data = x;
    ultimo->next = m_tail;
    m_tail->prev = ultimo;
    
    if ( empty() ) 
    {
        m_head->next = ultimo;
        ultimo->prev = m_head;
    } 
    else 
    {
        Node * aux = m_head;
        
        while (aux->next != m_tail )
            aux = aux->next;
            
        aux->next = ultimo;
        ultimo->prev = aux;
    }
    
    m_size++;
}

template < typename T >
void List<T>::pop_back() 
{
    if ( not empty() ) 
    {
        Node * aux = m_tail->prev;
        
        m_tail->prev->prev->next = m_tail;
        m_tail->prev = m_tail->prev->prev;
        
        delete aux;
    }
    else
    {
        throw std::bad_function_call::bad_function_call("List is empty!");
    }
}

template < typename T >
void List<T>::clear() 
{
    if ( !empty() )
    {
        Node * atual = m_head->next;
        Node * proximo = atual->next;
        while (proximo != m_tail) 
        {
            delete atual;
            atual = proximo;
            proximo = proximo->next;
        }
        
        delete atual;
        m_head->next = m_tail;
        m_tail->prev = m_head;
        m_size = 0;
    }
}

template < typename T >
void List<T>::push_front( const T & x ) 
{
    Node * primeiro = new Node;
    
    primeiro->data = x;
    primeiro->next = m_head->next;
    primeiro->prev = m_head;
    
    m_head->next = primeiro;
    m_size++;
}

template < typename T >
void List<T>::pop_front() 
{
    if ( not empty() ) 
    {
        Node * aux = m_head->next;
        m_head->next = aux->next;
        (aux->next)->prev = m_head;
        
        delete aux;
        
        m_size--;
    }
    else
    {
        throw std::bad_function_call::bad_function_call("List is empty!");
    }
}


template < typename T >
const T & List<T>::back() const 
{
    if ( m_head->next == m_tail )
        throw std::bad_function_call::bad_function_call("List is empty!");
  
    return (m_tail->prev)->data;
}


template < typename T >
const T & List<T>::front() const 
{
    if ( m_head->next == m_tail )
        throw std::bad_function_call::bad_function_call("List is empty!");
        
    return (m_head->next)->data;
}

template < typename T >
void List<T>::assign( const T & x ) 
{
    if ( not empty() ) 
    {
        Node * aux = m_head->next;
        while (aux != m_tail) 
        {
            aux->data = x;
            aux = aux->next;
        }
    }
}

// IMPLEMENTAÇÃO DOS ITERADORES

template < typename T >
typename List<T>::const_iterator List<T>::cbegin() const
{
    return const_iterator( m_head->next );
    // return iterator( &mi_vector[0] );
}

template < typename T >
typename List<T>::const_iterator List<T>::cend() const
{
    return const_iterator( m_tail );
    
}

template < typename T >
typename List<T>::iterator List<T>::begin()
{
    return iterator( m_head->next );
    // return iterator( &mi_vector[0] );
}

template < typename T >
typename List<T>::iterator List<T>::end()
{
    return iterator( m_tail );
}

template < typename T >
typename List<T>::iterator List<T>::insert_after(const_iterator pos, const T & x) 
{
    Node * aux = new Node;
    Node * aux2 = pos.current->next;
    aux->data = x;
    aux->next = pos.current->next;;
    aux2->prev = aux;
    aux->prev = pos.current;
    pos.current->next = aux;
    m_size++;
    return iterator(aux);
}

template < typename T >
typename List<T>::iterator List<T>::erase_after( const_iterator pos ) 
{
    if (pos.current->next != m_tail && pos.current != m_tail ) 
    {
        Node * aux = pos.current->next;
        pos.current->next = aux->next;
        (aux->next)->prev = pos.current;
        delete aux;
        m_size--;
        return iterator(pos.current->next);
    }
    return iterator(pos.current);
}

template < typename T >
typename List<T>::iterator List<T>::erase_after( const_iterator first, const_iterator last ) {
    if (!empty()) {
        Node * ult;
        Node * del;
        ult = first.current->prev;
        
        for (const_iterator i = first; i.current->next != last.current; i++) {
            del = i.current;
            delete del;
            m_size--;
        }
        ult->next = last.current;
        last.current->prev = ult;
        m_size--;
        return iterator(last.current);
    }
    
    return iterator (first.current);
}

template < typename T >
typename List<T>::iterator List<T>::insert_after( const_iterator pos, std::initializer_list<T> ilist ) {
    for (auto i : ilist) {
        Node * v = new Node;
        v->data = i;
        v->next = pos.current->next;
        v->prev = pos.current;
        pos.current->next = v;
        m_size++;
    }
    return iterator (pos.current->next);
}

template < typename T >
typename List<T>::const_iterator List<T>::find( const T & x) const 
{
    for (const_iterator i = cbegin(); i != cend(); i++) {
        if (i.current->data == x)  {
            return const_iterator(i.current);
        }
    }
    return const_iterator(m_tail);
}

template < typename T >
void List<T>::assign ( std::initializer_list <T> ilist ) {
    clear();
    for(auto n : ilist) {
        push_back(n);
    }
}
