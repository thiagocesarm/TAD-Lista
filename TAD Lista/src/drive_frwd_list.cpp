#include <iostream>
#include "list_lib.h"

// g++ -Wall -std=c++11 -I include/ src/drive_vector.cpp

int main()
{
    
    Forward_List<int> forw; 
    
    
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