#include "Node.h"

void List::insert(int value, int position) {
    Node *parent = first;
    for (; position - 1; --position) {
        parent = parent->next;
    }
    insert(parent, value);
}

void List::insert(Node *parent, int value) {
    Node *newNode = new Node(value, parent->next);
    parent->next = newNode;
    ++size;
}

bool List::remove(int value) {
    Node *toRemove = first;
    while (toRemove->next != nullptr && toRemove->value != value) {
        toRemove = toRemove->next;
    }

    if (toRemove->next != nullptr) {
        return remove(toRemove);
    }

    return false;
}

bool List::remove(Node *node) {
    Node *nextNode = node->next;

    node->value = node->next->value;
    node->next = node->next->next;

    delete nextNode;
    --size;
    return true;
}

void List::print(ostream &out) {
    Node *cur = first;
    while (cur != nullptr) {
        out << cur->value << "  ";
        cur = cur->next;
    }
}

List::~List() {
    Node* next = first;
    Node* toDelete;
    for (int i = 0; i < size; ++i) {
        toDelete = next;
        next = next->next;
        delete toDelete;
    }
}
