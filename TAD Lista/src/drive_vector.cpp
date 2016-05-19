/*! 
 *  @file drive_vector.cpp
 *  @brief Arquivo com a função main() que testa a classe Vector.
 *
 */

#include <iostream>
#include <cassert>
#include <cmath>
#include "list_lib.h"

int main()
{
    // vec1 inicializado com 1 elemento por padrão
    Vector<int> vec1;
    Vector<int> vec2(3);
    
    // Testando empty()
    assert(vec1.empty() == true);
    assert(vec2.empty() == true);
    
    // Testando capacity()
    assert(vec1.capacity() == 1);
    assert(vec2.capacity() == 3);
    
    // Testando size()
    assert(vec1.size() == 0);
    assert(vec2.size() == 0);
    
    // Testando push_back()
    vec1.push_back(1);
    vec1.push_back(2); //vec1. dobra de tamanho - reserve() foi chamado
    vec1.push_back(4); //vec1. dobra de tamanho - reserve() foi chamado
    vec1.push_back(8);
    vec1.push_back(16); //vec1. dobra de tamanho - reserve() foi chamado
    
    assert(vec1.capacity() == 8);
    assert(vec1.size() == 5);
    
    vec2.push_back(1);
    vec2.push_back(3);
    vec2.push_back(9);
    vec2.push_back(27); //vec2. dobra de tamanho - reserve() foi chamado
    vec2.push_back(81);
    
    assert(vec2.capacity() == 6);
    assert(vec2.size() == 5);
    
    // Testando at() e operator[]
    assert(vec1.at(0) == 1);
    assert(vec1.at(1) == 2);
    assert(vec1[2] == 4);
    assert(vec1[3] == 8);
    assert(vec1[4] == 16);
    
    assert(vec2.at(0) == 1);
    assert(vec2.at(1) == 3);
    assert(vec2[2] == 9);
    assert(vec2[3] == 27);
    assert(vec2[4] == 81);
    
    assert(vec1.front() == 1);
    assert(vec1.back() == 16);
    
    assert(vec2.front() == 1);
    assert(vec2.back() == 81);
    
    // Testando iteradores
    
    Vector<int>::iterator it1 = vec1.begin();
    Vector<int>::iterator it2 = vec2.begin();
    
    for(size_type i = 0; i < vec1.size(); ++i)
    {
        assert(*it1 == pow(2, i));
        it1++;
    }
    
    for(size_type i = 0; i < vec2.size(); ++i)
    {
        assert(*it2 == pow(3, i));
        it2++;
    }
    
    // Testando assign() e iteradores
    vec1.assign(2);
    vec2.assign(3);
    
    it1 = vec1.begin();
    it2 = vec2.begin();
    
    for(size_type i = 0; i < vec1.size(); ++i)
    {
        assert(*it1 == 2);
        it1++;
    }
    
    for(size_type i = 0; i < vec2.size(); ++i)
    {
        assert(*it2 == 3);
        it2++;
    }
    
    // Testando clear();
    
    vec1.clear();
    vec2.clear();
    
    assert(vec1.empty() == true);
    assert(vec2.empty() == true);
    
    return EXIT_SUCCESS;
}