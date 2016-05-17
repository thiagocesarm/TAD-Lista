#include <iostream>
#include "list_lib.h"

// g++ -Wall -std=c++11 -I include/ src/drive_vector.cpp

int main()
{
    Vector<int> vec;
    
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
    
    
    
        
    return EXIT_SUCCESS;
}