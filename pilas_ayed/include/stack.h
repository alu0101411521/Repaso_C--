#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

// Pila dinamica
template <class Type>
class Stack_v_t{
public:
//constructores
Stack_v_t();

//destructores
~Stack_v_t();

//funciones
void Insercion(const Type& aux);
void Extraccion();
Type Top();
bool Empty();

//sobrecarga de operadores
template <class T>
friend std::ostream& operator<<(std::ostream& os, const Stack_v_t<Type>& ejemplo);


//private:
  std::vector<Type> v_;
};

//constructores
template <class Type>
Stack_v_t<Type>::Stack_v_t() : v_() {
}

//destructores
template <class Type>
 Stack_v_t<Type>::~Stack_v_t()  {}


//funciones
template <class Type>
bool Stack_v_t<Type>::Empty(){
  return v_.size() == 0;
}



template <class Type>
void Stack_v_t<Type>::Extraccion(){
  int tamanio = v_.size();
  if(!Empty()){
    for(int i = 1; i < tamanio; ++i){
      v_[i - 1] = v_[i];
    }
    v_.resize(tamanio - 1);
  }
}

template <class Type>
void Stack_v_t<Type>::Insercion(const Type& aux) {
  if(!Empty()){
  v_.resize(v_.size() + 1);
  int tamanio = v_.size();
    for(int i = tamanio - 1; i >= 0; --i){
      v_[i + 1] = v_[i];
    }
    v_[0] = aux;
    return;
  }
  v_.push_back(aux);
}

template <class Type>
Type Stack_v_t<Type>::Top() {
Type aux = v_[0];
return aux;
}


//sobrecarga de operadores
template <class Type>
std::ostream& operator<<(std::ostream& os, const Stack_v_t<Type>& ejemplo){
int tamanio = ejemplo.v_.size();
os << "{";
for(int i = 0; i < tamanio; ++i){
  os << " " << ejemplo.v_[i] << " ";
}
os << "}";
return os;
}

#endif