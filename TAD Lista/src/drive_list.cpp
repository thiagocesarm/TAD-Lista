/*! 
 *  @file drive_list.cpp
 *  @brief Arquivo com a função main() que testa a classe List.
 *
 */

#include <iostream>
#include <cassert>
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
    
    lst2.push_front(32);
    lst2.push_front(16);
    lst2.push_front(8);
    lst2.push_front(4)
    lst2.push_front(2);
    lst2.push_front(1);
    
    assert(lst1.size() == 11);
    assert(lst1.front() == 1);
    assert(lst1.back() == 1024);
    
    // Testando iteradores
    
    lsttor<int>::iterator it1 = lst1.begin();
    lsttor<int>::iterator it2 = lst2.begin();
    
    for(size_type i = 0; i < lst1.size(); ++i)
    {
        assert(*it1 == pow(2, i));
        it1++;
    }
    
    for(size_type i = 0; i < lst2.size(); ++i)
    {
        assert(*it2 == pow(3, i));
        it2++;
    }
    
    // Testando assign() e iteradores
    lst1.assign(2);
    lst2.assign(3);
    
    it1 = lst1.begin();
    it2 = lst2.begin();
    
    for(size_type i = 0; i < lst1.size(); ++i)
    {
        assert(*it1 == 2);
        it1++;
    }
    
    for(size_type i = 0; i < lst2.size(); ++i)
    {
        assert(*it2 == 3);
        it2++;
    }
    
    // Testando clear();
    
    lst1.clear();
    lst2.clear();
    
    assert(lst1.size() == 0);
    assert(lst2.size() == 0);
    
    auto cit = forw.find(9);
    std::cout << "Element size#" <<  ": " << forw.size() << "\n";
    forw.insert_after(cit, {2, 4, 5});
    List<int>::iterator pit = forw.begin();
    std::cout << "Element size#" <<  ": " << forw.size() << "\n";
    for(size_type i = 0; i < forw.size(); ++i)
    {
        std::cout << "Element #" << i << ": " << *pit << "\n";
        pit++;
    }

        
    return EXIT_SUCCESS;
}