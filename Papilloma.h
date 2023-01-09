//
// Created by matan on 09/01/2023.
//

#ifndef UNTITLED19_PAPILLOMA_H
#define UNTITLED19_PAPILLOMA_H

#include "Virus.h"
class Papilloma: public Virus{
public:
    Papilloma(const string &name, int lengthV, int pm, int *target, const int *vector,string type);
};


#endif //UNTITLED19_PAPILLOMA_H
