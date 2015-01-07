#include "LinkedList.h"

LinkedList::LinkedList() : m_size(0)
{
}

ListNode* LinkedList::search(const T & key)
{
	ListNode * h = start_node;

	while (h && h->get_key() != key)
		h = h->get_next();

	return h;
}

/**
 * Adding a key should add it sorted, which means that we have to loop through the values while they are smaller than
 */
void LinkedList::add(T const & key)
{
    ListNode *n = new ListNode(key);

    // If start node is null, just add the new node
    if (!start_node) {
        start_node = n;
        m_size++;
        return;
    }

    ListNode *h = start_node;

    // If first startnode key > our key, then change positioning
    if (start_node->get_key() > key) {
        h = start_node;
        n->set_next(h);
        start_node = n;
        m_size++;
        return;
    }

    // If we got an element already, go to the position where the m_next key is > then this key
    while (h->get_next() && h->get_next()->get_key() < key) {
        h = h->get_next();
    }

    n->set_next(h->get_next());
    h->set_next(n);

    m_size++;

    return;
}

void LinkedList::add_front(T const & key)
{
    if (!start_node) {
        start_node = new ListNode(key);
        m_size++;
        return;
    }

    ListNode *h = new ListNode(key);
    h->set_next(start_node);
    start_node = h;
    m_size++;
}

void LinkedList::print(ostream & os) const
{
    ListNode * h = start_node;

    while (h) {
        os << "Value: " << std::to_string(h->get_key()) << std::endl;
        h = h->get_next();
    }
}

void LinkedList::print() const
{
    ListNode * h = start_node;

    while (h) {
        std::cout << "Value: " << std::to_string(h->get_key()) << std::endl;
        h = h->get_next();
    }
}

/**
 * Remove the first element
 */
void LinkedList::remove_front() {
    ListNode *h = start_node;
    start_node = start_node->get_next();
    delete h;
    m_size--;
}

/**
 * Remove the element with the given key
 */
void LinkedList::remove(const T &key) {
    ListNode *h = start_node;
    ListNode *t;

    // If list is empty, return
    if (!h) return;

    // If the first element is our key, remove and return
    if (h->get_key() == key) {
        t = h;
        start_node = h->get_next();
        delete t;
        m_size--;
        return;
    }

    // Else search for it
    while (h->get_next() && h->get_next()->get_key() != key) {
        h = h->get_next();
    }

    // Nothing found
    if (!h->get_next()) {
        std::cout << "Could not find node." << std::endl;
        return;
    }

    std::cout << "Found: " << h->get_next()->get_key() << std::endl;

    // Key found, delete
    t = h->get_next(); // Node to delete
    h->set_next(h->get_next()->get_next()); // Set h node on the m_next node
    delete t;
    m_size--;

    std::cout << "Removed key" << std::endl;
}

// Destroy the list
LinkedList::~LinkedList() {
    ListNode *h = start_node;
    ListNode *t;

    while (h && h->get_next()) {
        t = h;
        h = h->get_next();

        if (h != NULL)
            delete t;
    }

    if (h != NULL)
       delete h;
}