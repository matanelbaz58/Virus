//
// Created by matan on 22/12/2022.
//

#ifndef UNTITLED19_WORLD_H
#define UNTITLED19_WORLD_H

#include <ostream>
#include  "Virus.h"
#include "Queue.h"
class World {
private:
    Queue<Virus>* queue;
    int amount_virus;

    Virus* the_best_virus;
    bool is_error_zero;
public:
    explicit World(int amount_virus);
    void add_virus(string name, int length_v, int *target, const int *vector, int index,char type);    //  add virus to pool
    ~World();

    World(const World &w);
    World &operator=(const World &w);//copy assignment operator




    bool isErrorZero() const;

    void updating_all_single();

    void operator++(int);

    void print_world();



};


#endif //UNTITLED19_WORLD_H
