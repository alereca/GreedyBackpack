//
// Created by ale on 4/24/19.
//

#ifndef ALGORITMOSGENETICOSC___RANDOMNUMBERGENERATOR_H
#define ALGORITMOSGENETICOSC___RANDOMNUMBERGENERATOR_H

#include <random>

namespace RandomNumberGenerator{
    extern std::random_device rd;
    extern std::mt19937 rg;

    int GetRandomInteger(int, int);
    double GetRandomReal(double, double);
}

#endif //ALGORITMOSGENETICOSC___RANDOMNUMBERGENERATOR_H
