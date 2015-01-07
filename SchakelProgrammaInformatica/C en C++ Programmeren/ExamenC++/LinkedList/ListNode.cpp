#include <iostream>
#include "ListNode.h"

using std::cout;

ListNode::ListNode() : m_key(0), m_next(nullptr) {
};

ListNode::ListNode(const T& key) : m_key(key), m_next(nullptr) {
};

ListNode::ListNode(const T& key, ListNode *next) : m_key(key), m_next(next) {
};

ListNode::~ListNode() {
    cout << "ListNode Destructed" << std::endl;
}
