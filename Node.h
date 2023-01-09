//
// Created by matan on 08/01/2023.
//

#ifndef UNTITLED23_NODE_H
#define UNTITLED23_NODE_H

template<class T>
class Node {
private:
    T *data;
    Node *next;

public:
    Node(T data) {
        Node::data = new T(data);
        next = nullptr;
    }
    ~Node(){
        delete data;
    }

    void setData(T *data) {
        Node::data = data;
    }

    void setNext(Node *next1) {
         next = next1;
    }

    T *getData() const {
        return data;
    }

    Node *getNext() const {
        return next;
    }

};


#endif //UNTITLED23_NODE_H
