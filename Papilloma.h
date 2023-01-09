//
// Created by matan on 09/01/2023.
//

#ifndef UNTITLED19_PAPILLOMA_H
#define UNTITLED19_PAPILLOMA_H

#include "Virus.h"
class Papilloma: public Virus{
public:
    Papilloma(const string &name, int lengthV, int *target, const int *vector,char type);
};


#endif //UNTITLED19_PAPILLOMA_H
