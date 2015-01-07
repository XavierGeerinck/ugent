#include <iostream>
#include "LinkedList.h"

using std::cout;

int main() {
    cout << "Testing" << endl;

    LinkedList list;
    list.add(10);
    list.add(10);
    list.add(1);
    list.add(8);
    list.add(3);
    list.add(7);
    list.add(4);
    list.add(9);
    list.add(6);
    list.add(5);
    list.add(2);

    cout << "Added " << list.get_size() << " nodes." << endl;

    // Remove both 10's, 4 and 1 (Testing remove front, remove end, remove double, remove mid)
    list.remove(10);
    list.remove(10);
    list.remove(4);
    list.remove(1);

    list.print(std::cout);

    cout << "Out of scope, Removed list, should show " << list.get_size() << " removed items" << endl;
}