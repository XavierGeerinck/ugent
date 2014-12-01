#ifndef MAIN_LISTNODE_H
#define MAIN_LISTNODE_H

#include "LinkedList.h"

typedef int T;
class ListNode
{
    private:
        T key;
        ListNode * next;

    public:
        ListNode();
        ~ListNode();
        T get_key() const;
        ListNode* get_next();
        void set_next(ListNode * next);
        ListNode(const T&);
        ListNode(const T&, ListNode * next);

};

#endif