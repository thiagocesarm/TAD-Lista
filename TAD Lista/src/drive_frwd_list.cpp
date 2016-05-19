#include <iostream>
#include <cassert>
#include "list_lib.h"

int main()
{
    
    Forward_List<int> frw; 
    
    if ( frw.empty() )
        std::cout << "Empty list!\n";
        
    std::cout << ">>> Pushing back four elements:\n";
        
    frw.push_back(7);    
    frw.push_back(14);    
    frw.push_back(21);    
    frw.push_back(28);  
    
    std::cout << ">>> Pushing front four elements:\n";
        
    frw.push_front(11);    
    frw.push_front(22);    
    frw.push_front(33);    
    frw.push_front(44);
    
    Forward_List<int>::iterator it = frw.begin();
    
    std::cout << ">>> Vector size: " << frw.size() << "\n";
    
    for(size_type i = 0; i < frw.size(); ++i)
    {
        std::cout << "Element #" << i << ": " << *it << "\n";
        it++;
    }
    
    std::cout << ">>> Front element: " << frw.front() << "\n";
    std::cout << ">>> Back element: " << frw.back() << "\n";
    
    std::cout << "Assigning 120 to all elements on vector.\n";
    
    frw.assign(120);
    
    std::cout << "Popping back 2 elements.\n";
    
    frw.pop_back();
    frw.pop_back();
    
    std::cout << "Popping front 2 elements.\n";
    
    frw.pop_front();
    frw.pop_front();
    
    std::cout << ">>> Front element: " << frw.front() << "\n";
    std::cout << ">>> Back element: " << frw.back() << "\n";

    std::cout << ">>> Clearing vector.\n";
    
    frw.clear();
    
    if ( frw.empty() )
        std::cout << "Empty vector!\n";
        
    frw.push_front(11);    
    frw.push_front(22);    
    frw.push_front(33);    
    frw.push_front(44);
    
    auto cit = frw.find(22);
    frw.erase_after(cit);
    std::cout << "Element #" <<  ": " << frw.size() << "\n";
    Forward_List<int>::iterator pit = frw.begin();
    for(size_type i = 0; i < frw.size(); ++i)
    {
        std::cout << "Element #" << i << ": " << *pit << "\n";
        pit++;
    }
    return EXIT_SUCCESS;
}