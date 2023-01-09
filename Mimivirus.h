//
// Created by matan on 09/01/2023.
//

#ifndef UNTITLED19_MIMIVIRUS_H
#define UNTITLED19_MIMIVIRUS_H

#include "Virus.h"
class Mimivirus: public Virus{
public:
    Mimivirus(const string &name, int lengthV, int pm, int *target, const int *vector,string type);
};


#endif //UNTITLED19_MIMIVIRUS_H
