//
// Created by matan on 09/01/2023.
//

#ifndef UNTITLED19_MIMIVIRUS_H
#define UNTITLED19_MIMIVIRUS_H

#include "Virus.h"
class Mimivirus: public Virus{
public:
    Mimivirus(const string &name, int lengthV, int *target, const int *vector,char type);
};


#endif //UNTITLED19_MIMIVIRUS_H
