//
// Created by matan on 08/01/2023.
//

#ifndef UNTITLED19_LENTIVIRUS_H
#define UNTITLED19_LENTIVIRUS_H

#include "Virus.h"
class Lentivirus : public Virus{
public:
    Lentivirus(const string &name, int lengthV, int *target, const int *vector,char type);
};


#endif //UNTITLED19_LENTIVIRUS_H
