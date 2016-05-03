// This is a stub code (or skeleton code) just to allow the first compilation.

#include <iostream>
#include <stdexcept>
#include "les_v1.h"

using namespace std;

//! Prints the list.
/*! This a debugging function that prints the list content.
 *  @param _pAIL Pointer to the head of the list. If NULL, list is empty.
 */
void print( SNPtr _pAIL )
{
    std::cout << "Linked list\n[ ";
    while( _pAIL != nullptr )
    {
        std::cout << _pAIL->miData << " ";
        _pAIL = _pAIL->mpNext;
    }
    std::cout << "]\n";
}

//! Length of the list.
/*! Calculates and return the length of the list. Length is zero, if list is empty.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 *  @return The length.
 */
int length( SNPtr _pAIL )
{
    int i(0);
    while( _pAIL != nullptr )
    {
        i++;
        _pAIL = _pAIL->mpNext;
    }
    return i;
}


bool empty( SNPtr _pAIL )
{
    return ( _pAIL == nullptr );
}


void clear( SNPtr & _pAIL )
{
    if( not (_pAIL == nullptr) )
    {
        SNPtr current_node = _pAIL;
        SNPtr next_node = _pAIL->mpNext;
        while( next_node != nullptr )
        {
            delete current_node;
            current_node = next_node;
            next_node = next_node->mpNext;
        }

        delete current_node;

        _pAIL = nullptr;
    }
}


bool front( SNPtr _pAIL, int & _retrievedVal )
{
    if ( _pAIL == nullptr )
        return false;

     _retrievedVal = _pAIL->miData;
    return true;
}


bool back( SNPtr _pAIL, int & _retrievedVal )
{
    if ( _pAIL == nullptr )
        return false;

    while( _pAIL->mpNext != nullptr )
    {
        _pAIL = _pAIL->mpNext;
    }

    _retrievedVal = _pAIL->miData;
    return true;
}


bool pushFront( SNPtr & _pAIL, int _newVal )
{
    SNPtr new_node(nullptr);
    try
    {
        new_node = new SLLNode;
    }

    catch ( const std::bad_alloc & e )
    {
        return false;
    }

    new_node->miData = _newVal;
    new_node->mpNext = _pAIL;
    _pAIL = new_node;

    return true;
}


bool pushBack( SNPtr & _pAIL, int _newVal )
{
    SNPtr new_node(nullptr);
    try
    {
        new_node = new SLLNode;
    }

    catch ( const std::bad_alloc & e )
    {
        return false;
    }

    new_node->miData = _newVal;
    new_node->mpNext = nullptr;

    if ( _pAIL == nullptr )
        _pAIL = new_node;
    else
    {
        SNPtr work = _pAIL;
        while( work->mpNext != nullptr )
        {
            work = work->mpNext;
        }

        work->mpNext = new_node;
    }

    return true;
}

bool popFront( SNPtr & _pAIL, int & _retrievedVal )
{
    if (_pAIL == nullptr )
        return false;

    SNPtr new_head = _pAIL->mpNext;

    _retrievedVal = _pAIL->miData;

    // Free memory from element deleted;
    delete _pAIL;

    _pAIL = new_head;

    return true;
}


bool popBack( SNPtr & _pAIL, int & _retrievedVal )
{
    if ( _pAIL == nullptr )
        return false;

    SNPtr current_node = _pAIL;
    SNPtr next_node = _pAIL->mpNext;
    SNPtr next_next_node = next_node->mpNext;

    while ( next_next_node != nullptr )
    {
        current_node = next_node;
        next_node = current_node->mpNext;
        next_next_node = next_node->mpNext;
    }

    _retrievedVal = next_node->miData;

    delete next_node;

    current_node->mpNext = nullptr;

    return true;
}


SNPtr find( SNPtr _pAIL, int _targetVal )
{
    // IF is NOT the case that:
    //  - the element is found on the head of the list or
    //  - the list is empty.
    //
    // Continue to find the element
    if ( !( empty(_pAIL) or _pAIL->miData == _targetVal ) )
    {
        while( _pAIL->mpNext != nullptr )
        {
            if ( _pAIL->mpNext->miData == _targetVal)
                return _pAIL;

            _pAIL = _pAIL->mpNext;
        }
    }

    return nullptr;
}

bool insert( SNPtr & _pAIL, SNPtr _pAnte, int _newVal )
{
    if (  _pAIL == nullptr or _pAnte == nullptr )
        return pushFront(_pAIL, _newVal);
    else
    {
        SNPtr new_node;

        try
        {
            new_node = new SLLNode;
        }

        catch (const std::bad_alloc & e)
        {
            return false;
        }

        new_node->miData = _newVal;

        new_node->mpNext = _pAnte->mpNext;
        _pAnte->mpNext = new_node;
    }

    return true;
}


bool remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal )
{
    if ( _pAIL == nullptr )
        return false;


    if ( _pAnte == nullptr )
    {
        _retrievedVal = _pAIL->miData;
        SNPtr new_head = _pAIL->mpNext;
        delete _pAIL;
        _pAIL = new_head;        
    }
    else
    {
        if (_pAnte->mpNext == nullptr)
            return false;

        SNPtr aux;

        aux = _pAnte->mpNext;
        _retrievedVal = aux->miData;
        _pAnte->mpNext = aux->mpNext;

        delete aux;
    }

    return true;
}


//**** ===================[ End of les_v1.cpp ]=================== ****// 
