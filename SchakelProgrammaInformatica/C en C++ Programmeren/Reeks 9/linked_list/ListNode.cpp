#include "ListNode.h"

ListNode::ListNode() : m_key(0), m_next(NULL) {
};

ListNode::ListNode(const T &key) : m_key(key), m_next(NULL) {
};

ListNode::ListNode(const T &key, ListNode * next) : m_key(key), m_next(next) {
};

ListNode::~ListNode() {
}