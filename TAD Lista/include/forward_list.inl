#include "list_lib.h"
#include <stdexcept>

using namespace std;

template < typename T >
Forward_List<T>::Forward_List() :
    m_size(0),
    m_head(new Node),
    m_tail(new Node)
{
    m_head->next = m_tail;
}

template < typename T >
Forward_List<T>::~Forward_List()
{
    clear();
    delete m_head;
    delete m_tail;
}


template < typename T >
bool Forward_List<T>::empty() 
{
    return ( m_head->next == m_tail );
}


template < typename T >
size_type Forward_List<T>::size() const 
{
    return m_size;
}


template < typename T >
void Forward_List<T>::push_back( const T & x )
{
    Node * ultimo = new Node;
    
    ultimo->data = x;
    ultimo->next = m_tail;
    
    if ( empty() ) 
    {
        m_head->next = ultimo;
    } 
    else 
    {
        Node * aux = m_head;
        
        while (aux->next != m_tail )
            aux = aux->next;
            
        aux->next = ultimo;
    }
    
    m_size++;
}


template < typename T >
void Forward_List<T>::pop_back() 
{
    if ( !empty() ) 
    {
        Node * ult;
        Node * del;
        ult = m_head;
        del = m_head->next;
        
        while (del->next != m_tail) 
        {
            ult = del;
            del = ult->next;
        }
        
        delete del;
        
        ult->next = m_tail;
        m_size--;
    }
}


template < typename T >
void Forward_List<T>::clear() 
{
    if ( not empty() )
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
        
        m_size = 0;
        m_head->next = m_tail;
    }
}


template < typename T >
void Forward_List<T>::push_front( const T & x ) 
{
    Node * primeiro = new Node;
    
    primeiro->data = x;
    primeiro->next = m_head->next;
    
    m_head->next = primeiro;
    m_size++;
}

template < typename T >
void Forward_List<T>::pop_front() 
{
    if ( not empty() ) 
    {
        Node * aux = m_head->next;
        
        m_head->next = aux->next;
        delete aux;
        
        m_size--;
    }
}

template < typename T >
const T & Forward_List<T>::back() const 
{
    Node * aux = m_head->next;
    
    while (aux->next != m_tail) 
        aux = aux->next;
        
    return aux->data;
}

template < typename T >
const T & Forward_List<T>::front() const 
{
    return (m_head->next)->data;
}

template < typename T >
void Forward_List<T>::assign( const T & x ) 
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
