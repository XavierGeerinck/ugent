#ifndef LINKEDLIST_LINKEDLIST_H_
#define LINKEDLIST_LINKEDLIST_H_

#include "ListNode.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class ListNode;

typedef int T;
class LinkedList
{
    private:
        int m_size; // Keep the m_size, then we don't have to loop through it the whole time

    public:
        LinkedList();
        ~LinkedList();
        int get_size() const { return m_size;  };
        void add (const T &);
        void remove (const T &);
        void add_front(const T & key);
        void print(ostream & os) const;
        void print() const;
        void remove_front ();

    protected:
        ListNode *m_start_node; // Start node
        ListNode *search (const T & key);
};

#endif