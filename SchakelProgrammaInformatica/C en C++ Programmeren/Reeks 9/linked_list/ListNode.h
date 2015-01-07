#ifndef MAIN_LISTNODE_H
#define MAIN_LISTNODE_H

#include "LinkedList.h"

typedef int T;
class ListNode
{
    private:
        T m_key;
        ListNode *m_next;

    public:
        ListNode();
        ~ListNode();
        T get_key() const { return m_key; };
        ListNode* get_next() { return m_next; };
        void set_next(ListNode * next) { m_next = next; };
        ListNode(const T&);
        ListNode(const T&, ListNode * next);

};

#endif