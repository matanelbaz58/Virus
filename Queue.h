//
// Created by matan on 08/01/2023.
//

#ifndef UNTITLED23_QUEUE_H
#define UNTITLED23_QUEUE_H

#include "Node.h"
#include <iostream>
using namespace std;

template<class T>
class Queue {
private:
    Node<T> *first;
    Node<T> *last;
    int size_now;
public:
    Queue() : first(nullptr), last(nullptr), size_now(0) {

    }

    Queue<T> *copy_queue(Queue<T> const &queue) {
        clean();
        size_now = queue.size_now;
        if (queue.size_now == 0)
            return this;

        first = new Node<T>(*queue.first->getData());
        Node<T>* temp_q = queue.first->getNext();
        Node<T> *temp = first;
        while (temp_q) {
            temp->setNext(new Node<T>(*temp_q->getData()));
            temp_q = temp_q->getNext();
            temp = temp->getNext();
        }
        last = temp;
        return this;


    }

    ~Queue() {
        Node<T> *temp = first;
        Node<T>* temp_next;
        while (temp) {
            temp_next = temp->getNext();
            delete temp;
            temp = temp_next;
        }
        delete this;//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


    }
    T *operator[](int index){
        Node<T> *r = first;
        for( int i= 0 ; i<index; i ++){
            r = r->getNext();
        }
        return r->getData();

    }

    Queue(Queue<T> const &queue) {
        //if (queue == NULL)
        //    return;
        size_now = queue.size_now;
        if (queue.size_now == 0)
            return;

        first = new Node<T>(*queue.first->getData());
        Node<T>* temp_q = queue.first->getNext();
        Node<T> *temp = first;
        while (temp_q) {
            temp->setNext(new Node<T>(*temp_q->getData()));
            temp_q = temp_q->getNext();
            temp = temp->getNext();
        }
        last = temp;


    }

    void add(T val) {

        Node<T> *n = new Node<T>(val);
        //if the queue is empty
        if (size_now == 0) {
            first = n;
            last = n;
        } else {
            n->setNext(first);
            first = n;
        }
        size_now++;

    }

    void add_preference(T val) {
        Node<T>* n = new Node<T>(val);
        //if the queue is empty
        if (size_now == 0) {
            first = n;
            last = n;
        } else {
            Node<T> *temp = first;
            Node<T> *temp_before = first;
            while (temp) {
                if (*temp->getData() > val)
                    break;
                temp_before = temp;
                temp = temp->getNext();

            }
            if(temp == first){
                n->setNext(temp);
                first = n;
            } else {
                n->setNext(temp);
                temp_before->setNext(n);
            }
            if (temp_before == last) {
                last = n;
            }
        }

    }

    T *peek() {
        if (size_now == 0)
            return nullptr;
        return last->getData();
    }

    T *peek_first() {
        if (size_now == 0)
            return nullptr;
        return first->getData();
    }

    T *pop() {
        if (size_now == 0)
            return nullptr;
        size_now--;
        if (size_now == 1) {
            T *t = last->getData();
            last->setData(nullptr);
            delete last;
            first = nullptr;
            last = nullptr;
            return t;
        } else {
            Node<T> *temp = first;
            Node<T> *temp_before = first;
            while (temp!=last) {
                temp_before = temp;
                temp = temp->getNext();
            }

            T *t = last->getData();
            last->setData(nullptr);
            delete last;
            temp_before->setNext(nullptr);
            last = temp_before;
            return t;
        }

    }

    void clean() {
        Node<T>* temp = first;
        Node<T> *temp_next;
        while (temp) {
            temp_next = temp->getNext();
            delete temp;
            temp = temp_next;
        }
        first = nullptr;
        last = nullptr;
        size_now = 0;

    }

    int get_size() {
        return size_now;
    }

    Node<T>* pop_max() {
        if (size_now == 0)
            return nullptr;

        if (size_now == 1) {
            Node<T>* r = first;
            first = nullptr;
            last = nullptr;

            return r;
        }
        Node<T> *min = first;
        Node<T> *before_max = first;
        Node<T> *temp = first;
        Node<T> *before_temp = first;
        while (temp) {
            if (*temp->getData()   < *min->getData()) {
                min = temp;
                before_max = before_temp;
            }
            before_temp = temp;
            temp = temp->getNext();
        }
        if(min == first){
            first =min->getNext();

        } else if(min == last){
            last =before_max;
            before_max->setNext(nullptr);

        } else{
            before_max->setNext(min->getNext());
        }

        min->setNext(nullptr);
        return min;
    }

    //void pop_node(Node<T> before,Node<T> node_del) {
    //    if(size_now )
    //    if(node_del == first)
    //
//
    //}
    void sort() {
        Node<T>* start = pop_max();
        Node<T>* p = start;
        for(int i = 1; i < size_now ;  i++){
            p->setNext(pop_max());
            p = p->getNext();
        }
        first = start;
        last = p;

    }



    void print_queue() {
        Node<T> *p = first;

        while(p){
            cout<<" " <<*p->getData()<<"\n";
            p = p->getNext();
        }
    }


};


#endif //UNTITLED23_QUEUE_H
