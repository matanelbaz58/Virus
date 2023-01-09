//
// Created by matan on 22/12/2022.
//

#include "World.h"

#include <utility>
#include "Papilloma.h"
#include "Lentivirus.h"
#include "Mimivirus.h"

World::World(int amount_virus) : amount_virus(amount_virus), the_best_virus(nullptr) ,is_error_zero(false) {
    queue = new Queue<Virus>();
    //pool_virus2 = new Virus *[amount_virus];

}

void World::add_virus(string name, int length_v, int *target, const int *vector, int index,char type) {
    Virus *v;
    switch (type) {
        case 'P':
            v = new Papilloma(name, length_v,target, vector,type);
            break;
        case 'M':
            v = new Mimivirus(name, length_v,target, vector,type);
            break;
        case 'L':
            v = new Lentivirus(name, length_v,target, vector,type);
            break;

        
    }

    queue->add(*v);
    //pool_virus2[index] = v;
}

//void World::sort_virus() {
//    Virus *temp;
//    for(int i = 0; i < amount_virus;i++){
//        for(int j = i+1;j<amount_virus;j++){
//            if(pool_virus2[i]->getError() > pool_virus2[j]->getError()){
//                temp = pool_virus2[i];
//                pool_virus2[i] = pool_virus2[j];
//                pool_virus2[j] = temp;
//
//            }
//        }
//
//
//
//    }

//}

bool World::isErrorZero() const {
    return is_error_zero;
}

void World::updating_all_single() {
    for(int i = 0; i< amount_virus;i++){
        Virus *p = queue->pop();
        **p;
        queue->add(*p);
    }
    queue->sort();

    // check if there is a virus that has 0 error
    if(queue->peek_first()->getError() == 0)
        is_error_zero = true;

    //check who is the the_best_virus
    if(the_best_virus == nullptr )
        the_best_virus = new Virus(*queue->peek_first());
    else if(queue->peek_first()->getError() < the_best_virus->getError())
        the_best_virus = queue->peek_first();


}

void World::operator++(int) {
    queue->sort();
    Virus *best= queue->peek_first();
    Virus *p = nullptr;
    int count = 0;
    while (count< amount_virus){
         p = queue->pop();
         if(p->getType() != 'P')
             break;
         count++;
         queue->add(*p);
    }
    if(p!= nullptr & count != amount_virus) {
        *p = *best;
        queue->add(*p);
    }

}



void World::print_world() {
    queue->sort();
    queue->print_queue();

    cout<<"\n";
    if(the_best_virus != nullptr)
      cout<<*the_best_virus;

}

World::~World() {
    delete the_best_virus;
    delete queue;

    //delete pool_virus2;
}


World::World(const World &w) {
    amount_virus = w.amount_virus;
    is_error_zero = w.is_error_zero;
    the_best_virus = new Virus(*w.the_best_virus);
    //pool_virus2 = new Virus*[amount_virus];
    queue = new Queue<Virus>();
    for(int i = 0; i < amount_virus;i++){
        //pool_virus2[i] = new Virus(*w.pool_virus2[i]);
        queue->add(*(*queue)[i]);
    }

}

World &World::operator=(const World &w) {
    if(this == &w)
        return *this;
    amount_virus = w.amount_virus;
    is_error_zero = w.is_error_zero;
    the_best_virus = new Virus(*w.the_best_virus);
    queue->copy_queue(*w.queue);
   // for(int i = 0; i < amount_virus;i++){
   //     pool_virus2[i] = new Virus(*w.pool_virus2[i]);
   // }
    return *this;
}



