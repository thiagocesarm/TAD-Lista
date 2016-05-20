/*! 
 *  @file drive_list.cpp
 *  @brief Arquivo com a função main() que testa a classe List.
 *
 */

#include <iostream>
#include <cassert>
#include <cmath>
#include "list_lib.h"

int main()
{

    List<int> lst1;
    
    // Testando size()
    assert(lst1.size() == 0);
    
    // Testando empty();
    assert(lst1.empty() == true);
    
    // Testando push_back()
    lst1.push_back(64);
    lst1.push_back(128);
    lst1.push_back(256);
    lst1.push_back(512);
    lst1.push_back(1024);
    
    assert(lst1.size() == 5);
    assert(lst1.front() == 64);
    assert(lst1.back() == 1024);
    
    // Testando push_front()
    lst1.push_front(32);
    lst1.push_front(16);
    lst1.push_front(8);
    lst1.push_front(4);
    lst1.push_front(2);
    lst1.push_front(1);
    
    assert(lst1.size() == 11);
    assert(lst1.front() == 1);
    assert(lst1.back() == 1024);
    
    // Testando iterador
    List<int>::iterator it1 = lst1.begin();

    assert( *(lst1.begin()) == lst1.front() );
    
    for(size_type i = 0; i < lst1.size(); ++i)
    {
        assert(*it1 == pow(2, i));
        it1++;
    }

    // Testando pop_back();
    lst1.pop_back();
    lst1.pop_back();
    lst1.pop_back();

    assert(lst1.size() == 8);
    assert(lst1.back() == 128);

    // Testando pop_front();
    lst1.pop_front();
    lst1.pop_front();
    lst1.pop_front();

    assert(lst1.size() == 5);
    assert(lst1.front() == 8);

    // Testando assign()

    lst1.assign(2048);

    it1 = lst1.begin();
    
    for(size_type i = 0; i < lst1.size(); ++i)
    {
        assert(*it1 == 2048);
        it1++;
    }

    // Testando find()
    assert( lst1.find(2048) != lst1.end() );
    assert( lst1.find(33) == lst1.end() );
    assert( *(lst1.find(2048)) == 2048 );

    // Testando clear()
    lst1.clear();
    
    assert(lst1.size() == 0);

    List<int> lst2;

    lst2.push_back(10);
    lst2.push_back(20);
    lst2.push_back(30);
    lst2.push_back(40);
    lst2.push_back(50);

    auto cit = lst2.find(30);

    // Testando erase_after()
    lst2.erase_after(cit);

    auto pit = lst2.begin();

    for(size_type i = 0; i < lst2.size(); ++i)
    {
        std::cout << "Element #" << i << ": " << *pit << "\n";
        pit++;
    }

    std::cout << std::endl;

    // Testando insert_after()
    lst2.insert_after(cit, 35);

    pit = lst2.begin();

    for(size_type i = 0; i < lst2.size(); ++i)
    {
        std::cout << "Element #" << i << ": " << *pit << "\n";
        pit++;
    }

        
    return EXIT_SUCCESS;
}