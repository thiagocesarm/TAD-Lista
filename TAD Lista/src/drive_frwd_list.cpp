/*! 
 *  @file drive_frwd_list.cpp
 *  @brief Arquivo com a função main() que testa a classe List.
 *
 */

#include <iostream>
#include <cassert>
#include <cmath>
#include "list_lib.h"

int main()
{
    
    Forward_List<int> flst1;
    
    // Testando size()
    assert(flst1.size() == 0);
    
    // Testando empty();
    assert(flst1.empty() == true);
    
    // Testando push_back()
    flst1.push_back(64);
    flst1.push_back(128);
    flst1.push_back(256);
    flst1.push_back(512);
    flst1.push_back(1024);
    
    assert(flst1.size() == 5);
    assert(flst1.front() == 64);
    assert(flst1.back() == 1024);
    
    // Testando push_front()
    flst1.push_front(32);
    flst1.push_front(16);
    flst1.push_front(8);
    flst1.push_front(4);
    flst1.push_front(2);
    flst1.push_front(1);
    
    assert(flst1.size() == 11);
    assert(flst1.front() == 1);
    assert(flst1.back() == 1024);
    
    // Testando iterador
    Forward_List<int>::iterator it1 = flst1.begin();

    assert( *(flst1.begin()) == flst1.front() );
    
    for(size_type i = 0; i < flst1.size(); ++i)
    {
        assert(*it1 == pow(2, i));
        it1++;
    }

    // Testando pop_back();
    flst1.pop_back();
    flst1.pop_back();
    flst1.pop_back();

    assert(flst1.size() == 8);
    assert(flst1.back() == 128);

    // Testando pop_front();
    flst1.pop_front();
    flst1.pop_front();
    flst1.pop_front();

    assert(flst1.size() == 5);
    assert(flst1.front() == 8);

    // Testando assign()

    flst1.assign(2048);

    it1 = flst1.begin();
    
    for(size_type i = 0; i < flst1.size(); ++i)
    {
        assert(*it1 == 2048);
        it1++;
    }

    // Testando find()
    assert( flst1.find(2048) != flst1.end() );
    assert( flst1.find(33) == flst1.end() );
    assert( *(flst1.find(2048)) == 2048 );
    
    // Testando clear()
    flst1.clear();

    Forward_List<int> flst2;

    flst2.push_back(10);
    flst2.push_back(20);
    flst2.push_back(30);
    flst2.push_back(40);
    flst2.push_back(50);

    auto cit = flst2.find(30);

    // Testando erase_after()
    flst2.erase_after(cit);

    auto pit = flst2.begin();

    for(size_type i = 0; i < flst2.size(); ++i)
    {
        std::cout << "Element #" << i << ": " << *pit << "\n";
        pit++;
    }

    std::cout << std::endl;

    // Testando insert_after()
    flst2.insert_after(cit, 35);

    pit = flst2.begin();

    for(size_type i = 0; i < flst2.size(); ++i)
    {
        std::cout << "Element #" << i << ": " << *pit << "\n";
        pit++;
    }
    
    return EXIT_SUCCESS;
}