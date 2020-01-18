#ifndef OOP_DOROGI_LIB_H
#define OOP_DOROGI_LIB_H

#include <iostream>
#include <fstream>

using namespace std;

const int Roads = 9;

struct Doroga{

    char destination;
    char arrival;
    int length;
};

void fillind_mass(ifstream &file, Doroga *mass);

int choose_shortest(char destination, char arrival, Doroga* mass);

#endif //OOP_DOROGI_LIB_H
