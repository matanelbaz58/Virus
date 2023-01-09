//
// Created by matan on 08/01/2023.
//

#include "Lentivirus.h"

Lentivirus::Lentivirus(const string &name, int lengthV, int *target, const int *vector,char type) : Virus(name, lengthV,
                                                                                                        2, target,
                                                                                                        vector,type) {}
