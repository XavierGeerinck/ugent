#include "ListNode.h"

ListNode::ListNode() {
    this->key = 0;
    this->next = NULL;
};

ListNode::ListNode(const T &key) {
    this->key = key;
    this->next = NULL;
};

ListNode::ListNode(const T &key, ListNode * next) {
    this->key = key;
    this->next = next;
};

int ListNode::get_key() const {
    return key;
}

void ListNode::set_next(ListNode * next) {
    this->next = next;
}

ListNode* ListNode::get_next() {
    return next;
}

ListNode::~ListNode() {
}