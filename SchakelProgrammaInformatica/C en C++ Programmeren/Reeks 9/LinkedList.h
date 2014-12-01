#ifndef MAIN_LIST_H
#define MAIN_LIST_H

#include "ListNode.h"

#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class ListNode;

typedef int T;
class LinkedList
{
    private:
        int size; // Keep the size, then we don't have to loop through it the whole time

    public:
	    LinkedList();
	    ~LinkedList();
	    int get_size() const;
	    void add (const T &);
	    void remove (const T &);
        void add_front(const T & key);
        void print(ostream & os) const;
        void print() const;
        void remove_front ();
	    
    protected:
        ListNode * start_node; // Start node
        ListNode * search (const T & key);
};

#endif