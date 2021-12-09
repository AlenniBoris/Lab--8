#ifndef DIMA_S_NODE_H
#define DIMA_S_NODE_H

#include <ostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int _v, Node* _n = nullptr): value(_v), next(_n){}
};

class List{
public:
    Node* first;
    int size;

    List(): size(0), first(new Node(0)){}

    void insert(int value, int position);
    void insert(Node* parent, int value);

    bool remove(int value);
    bool remove(Node* node);

    void print(std::ostream& out);

    ~List();
};


#endif //DIMA_S_NODE_H
