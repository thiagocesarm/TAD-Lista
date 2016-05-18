#include <iostream>
#include "list_lib.h"

// g++ -Wall -std=c++11 -I include/ src/drive_vector.cpp

int main()
{
    Vector<int> vec;
    
    Forward_List<int> forw; 
    
    /*
    
    std::cout << ">>>" << vec.capacity() << "\n";
    vec.push_back(3);
    std::cout << ">>>" << vec.capacity() << "\n";
    vec.push_back(4);
    std::cout << ">>>" << vec.capacity() << "\n";
    vec.push_back(5);
    std::cout << ">>>" << vec.capacity() << "\n";
    vec.push_back(6);
    std::cout << ">>>" << vec.capacity() << "\n";
    vec.push_back(7);
    
    // vec.clear();
    
    if ( vec.empty() )
        std::cout << "Empty!\n";
    else
        std::cout << "NOT empty!\n";
        
    // vec.push_back(5);
        
    for(size_type i = 0; i < 5; ++i)
    {
        std::cout << vec.at(i) << "\n";
    }
    
    std::cout << ">>>" << vec.capacity() << "\n";
    
    */
    
    if ( forw.empty() )
        std::cout << "Empty!\n";
    else
        std::cout << "NOT empty!\n";
        
    forw.push_back(7);    
    forw.push_front(8);
    forw.push_back(9);
    forw.push_front(3);
    forw.push_front(4);
    forw.push_back(56);
    forw.pop_front();
    forw.pop_back();
    forw.assign(4);

    std::cout << "Trás: >>>" << forw.back() << "\n";
    std::cout << "Frente: >>>" << forw.front() << "\n";
    std::cout << "Tamanho: >>>" << forw.size() << "\n";

        
    return EXIT_SUCCESS;
}