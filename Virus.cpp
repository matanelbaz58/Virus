//
// Created by matan on 22/12/2022.
//

#include "Virus.h"

#include <utility>


Virus::Virus(string name, int length_v, int pm, int *target, const int *vector,char type) :
        name(std::move(name)), length_v(length_v), pm(pm), target(target),
        my_version(0),type(type) {

    version = new int[1];
    version[0] = 0;
    this->vector = new int[length_v];
    for (int i = 0; i < length_v; i++) {
        this->vector[i] = vector[i];
    }
    error = get_num_error();

}

double Virus::get_num_error() {
    double err = length_v;
    for (int i = 0; i < length_v; i++) {
        if (target[i] == vector[i])
            err--;
    }
    return err / length_v;
}

void Virus::operator*() {
    int index1;
    int index2;
    int temp;
    for (int i = 0; i < pm; i++) {
        index1 = rand() % length_v;
        index2 = rand() % length_v;
        temp = vector[index1];
        vector[index1] = vector[index2];
        vector[index2] = temp;
    }
    error = get_num_error();
}

Virus::Virus(const Virus &v) {
    type = v.type;
    name = v.name;
    length_v = v.length_v;
    error = v.error;
    pm = v.pm;
    version = v.version;
    my_version = v.my_version;
    target = v.target;
    vector = new int[length_v];
    for (int i = 0; i < length_v; i++) {
        vector[i] = v.vector[i];
    }


}

double Virus::getError() const {
    return error;
}


Virus::~Virus() {
    delete[] vector;
//    delete[] version;

}

Virus &Virus::operator=(const Virus &v) {
    if (this == &v)
        return *this;
    type = v.type;
    name = v.name;
    length_v = v.length_v;
    error = v.error;
    pm = v.pm;
    version = v.version;
    *version = *version + 1;
    my_version = *version;
    target = v.target;
    for (int i = 0; i < length_v; i++) {
        vector[i] = v.vector[i];
    }
    return *this;


}

Virus::Virus(Virus &&v) noexcept {
    type = v.type;
    name = move(v.name);
    length_v = v.length_v;
    error = v.error;
    pm = v.pm;
    version = v.version;
    v.version = nullptr;
    my_version = v.my_version;
    target = v.target;
    vector = v.vector;
    v.vector = nullptr;

}

Virus &Virus::operator=(Virus &&v) noexcept {
    if (this == &v)
        return *this;
    type = v.type;
    name = v.name;
    length_v = v.length_v;
    error = v.error;
    pm = v.pm;
    version = v.version;
    v.version = nullptr;
    my_version = v.my_version;
    target = v.target;
    swap(vector,v.vector);
//    vector = v.vector;
//    v.vector = nullptr;
    return *this;

}

char Virus::getType() const {
    return type;
}

ostream &operator<<(ostream &os, const Virus &virus) {
    if (virus.my_version == 0)
        os << virus.error << " "<< virus.type << " "<< virus.name << "\t";
    else
        os << virus.error << " "<<virus.type << " "<< virus.name << "_" << virus.my_version << "\t";
    for (int i = 0; i < virus.length_v; i++) {

        os << virus.vector[i] << " ";
    }
    return os;
}

bool Virus::operator<(const Virus &rhs) const {
    return error < rhs.error;
}

bool Virus::operator>(const Virus &rhs) const {
    return rhs < *this;
}

bool Virus::operator<=(const Virus &rhs) const {
    return !(rhs < *this);
}

bool Virus::operator>=(const Virus &rhs) const {
    return !(*this < rhs);
}
