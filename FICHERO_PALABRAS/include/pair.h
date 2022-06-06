#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>


class Pair {
 public:
//constructores
Pair(const int& contador, const std::string& palabra);
Pair();

//no metemos destructor pq no vamos a hacer nada

//Variables
int contador;
std::string palabra;
};

#endif
