//
// Created by matan on 22/12/2022.
//

#ifndef UNTITLED19_VIRUS_H
#define UNTITLED19_VIRUS_H

#include <iostream>

using namespace std;


class Virus {
private:
    char type;
    int *vector;
    string name;
    int length_v;
    double error;
    int pm;
    int* target;
    int *version;
    int my_version;






public:
    Virus() = delete;
    Virus( string name,int length_v,int pm,int* target,const int *vector,char type);

    double get_num_error();

     double getError() const;


    Virus(const Virus &v);//copy constructor 1
    virtual ~Virus();//destructor 2
    Virus &operator=(const Virus &v);//copy assignment operator 3
    Virus( Virus &&v)  noexcept ;//move constructor 4
    Virus &operator=(Virus &&v) noexcept; // move assignment operator 5
    void operator*();
    friend ostream &operator<<(ostream &os, const Virus &virus);


    bool operator<(const Virus &rhs) const;

    bool operator>(const Virus &rhs) const;

    bool operator<=(const Virus &rhs) const;

    bool operator>=(const Virus &rhs) const;

    char getType() const;


};


#endif //UNTITLED19_VIRUS_H
