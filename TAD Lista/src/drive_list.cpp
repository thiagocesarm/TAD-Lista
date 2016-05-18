#include <iostream>
#include "list_lib.h"

// g++ -Wall -std=c++11 -I include/ src/drive_vector.cpp

int main()
{
    
    List<int> forw; 
    
    
    if ( forw.empty() )
        std::cout << "Empty!\n";
    else
        std::cout << "NOT empty!\n";
        
    forw.push_back(7);
    forw.push_back(8);
    forw.push_back(9);
    forw.push_back(10);
    forw.push_back(11);
    
    forw.push_front(12);
    forw.push_front(13);
    forw.push_front(14);
    forw.push_front(15);
    forw.push_front(16);
        
    /*
    forw.push_back(7);    
    forw.push_front(8);
    forw.push_back(9);
    forw.push_front(3);
    forw.clear();
    forw.push_back(56);
    std::cout << "Trás: >>>" << forw.back() << "\n";
    forw.pop_front();
    std::cout << "Trás: >>>" << forw.back() << "\n";
    forw.pop_front();
    forw.assign(4);

    std::cout << "Trás: >>>" << forw.back() << "\n";
    std::cout << "Frente: >>>" << forw.front() << "\n";
    std::cout << "Tamanho: >>>" << forw.size() << "\n";
    */

        
    return EXIT_SUCCESS;
}