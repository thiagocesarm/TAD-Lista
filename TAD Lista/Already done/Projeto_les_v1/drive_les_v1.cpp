#include "les_v1.h"
#include <iostream>
#include <cassert>
using std::cout;


int main ( void ) {

    SNPtr pHead = nullptr;// nullptr;
    auto value(0);
    auto front_elm(0);
    auto back_elm(0);

    if ( empty(pHead) )
        cout << "Empty list!\n";


    cout << ">>> Inserting elements with 'pushFront'\n";

    pushFront( pHead, 600 );
    pushFront( pHead, 500 );
    pushFront( pHead, 400 );
    pushFront( pHead, 300 );
    pushFront( pHead, 200 );
    pushFront( pHead, 100 );

    print(pHead);
    cout << "List length: " << length(pHead) << "\n";
    assert( front(pHead, front_elm) == true );
    cout << "Front element: " << front_elm << "\n";
    assert( back(pHead, back_elm) == true );
    cout << "Back element: " << back_elm << "\n\n";



    cout << ">>> Inserting elements with 'pushBack'\n";

    pushBack( pHead, 700 );
    pushBack( pHead, 800 );
    pushBack( pHead, 900 );
    pushBack( pHead, 1000 );
    pushBack( pHead, 1100 );
    pushBack( pHead, 1200 );

    print(pHead);
    cout << "List length: " << length(pHead) << "\n";
    assert( front(pHead, front_elm) == true );
    cout << "Front element: " << front_elm << "\n";
    assert( back(pHead, back_elm) == true );
    cout << "Back element: " << back_elm << "\n\n";

    if ( popFront(pHead, value) )
        cout << "Using popFront\n>>>Element popped: " << value << "\n\n";

    if ( popFront(pHead, value) )
        cout << "Using popFront\n>>>Element popped: " << value << "\n\n";

    if ( popBack(pHead, value) )
        cout << "Using popBack!\n>>>Element popped: " << value << "\n\n";

    if ( popBack(pHead, value) )
        cout << "Using popBack!\n>>>Element popped: " << value << "\n\n";

    print(pHead);
    cout << "List length: " << length(pHead) << "\n";
    assert( front(pHead, front_elm) == true );
    cout << "Front element: " << front_elm << "\n";
    assert( back(pHead, back_elm) == true );
    cout << "Back element: " << back_elm << "\n\n";

    cout << ">>>Using 'insert' after " << pHead->mpNext->miData << "\n";
    assert( insert(pHead, pHead->mpNext, 450) == true );

    cout << ">>>Using 'insert' at the beginning\n";
    assert( insert(pHead, nullptr, 250) == true );

    print(pHead);
    cout << "List length: " << length(pHead) << "\n";
    assert( front(pHead, front_elm) == true );
    cout << "Front element: " << front_elm << "\n";
    assert( back(pHead, back_elm) == true );
    cout << "Back element: " << back_elm << "\n\n";





    cout << ">>>Using 'remove' to remove elements recently inserted\n";

    assert( remove(pHead, nullptr, value) == true );
    cout << "Element removed: " << value << "\n";

    assert( remove(pHead, pHead->mpNext, value) == true );
    cout << "Element removed: " << value << "\n";

    print(pHead);
    cout << "List length: " << length(pHead) << "\n";
    assert( front(pHead, front_elm) == true );
    cout << "Front element: " << front_elm << "\n";
    assert( back(pHead, back_elm) == true );
    cout << "Back element: " << back_elm << "\n\n";


    cout << ">>>Clearing list\n";
    clear(pHead);
    if (empty(pHead))
        cout << "List is now clear.\n";
    print(pHead);


    cout << "\n\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
