#include "../include/pair.h"

Pair::Pair(const int& contador, const std::string& palabra){
  this->contador = contador;
  this->palabra = palabra;
}

Pair::Pair(){
  contador = 0;
}