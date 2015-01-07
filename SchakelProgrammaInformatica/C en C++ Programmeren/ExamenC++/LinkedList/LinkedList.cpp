#include <iostream>
#include "LinkedList.h"

using std::cout;

LinkedList::LinkedList() : m_size(0) {
}

ListNode* LinkedList::search(const T & key)
{
    ListNode * h = m_start_node;

    while (h && h->get_key() != key)
        h = h->get_next();

    return h;
}

void LinkedList::print(ostream & os) const
{
    ListNode * h = m_start_node;

    while (h) {
        os << "Value: " << std::to_string(h->get_key()) << std::endl;
        h = h->get_next();
    }
}

void LinkedList::add_front(const T &key) {
    // First create the new ListNode
    ListNode *node = new ListNode(key);

    // Set the node->next to the start_node
    node->set_next(m_start_node);

    // Set the start_node to the node
    m_start_node = node;
    m_size++;
}

void LinkedList::remove_front() {
    ListNode *h = m_start_node;
    m_start_node = m_start_node->get_next();
    delete h;
    m_size--;
}

void LinkedList::remove(T const &key) {
    ListNode *h = m_start_node;

    // If first node, then remove the first node
    if (h && h->get_key() > key) {
        remove_front();
        return;
    }

    while (h->get_next() && h->get_next()->get_key() < key) {
        h = h->get_next();
    }

    ListNode *h2 = h->get_next();

    h->set_next(h->get_next()->get_next());
    delete h2;
    m_size--;
}

void LinkedList::add(T const &key) {
    ListNode *node = new ListNode(key);
    std::cout << "Created node" << std::endl;
    m_size++;

    // If the start_node is NULL, just set the startnode to our new node.
    if (!m_start_node) {
        m_start_node = node;
        return;
    }

    // If the first node is bigger then the new node, then set the new node as first node
    if (m_start_node->get_key() > key) {
        node->set_next(m_start_node);
        m_start_node = node;
        return;
    }

    // Else search for a spot to enter it
    ListNode *h = m_start_node;
    while (h->get_next() && h->get_next()->get_key() < key) {
        h = h->get_next();
    }

    node->set_next(h->get_next());
    h->set_next(node);
}

LinkedList::~LinkedList() {
    ListNode *h;

    // While we have nodes, keep deleting them
    while (m_start_node->get_next()) {
        h = m_start_node;
        m_start_node = m_start_node->get_next();

        delete h;
    }

    delete m_start_node;
}