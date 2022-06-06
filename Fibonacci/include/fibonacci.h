#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>
#include <vector>

template <class Type>
class Fibonacci {
 public:
  // constructores
  Fibonacci(const Type& val, const Type& val_2);

  // destructores
  ~Fibonacci();

  // Operaciones
  Type Calcular(const int indice);
  bool ItsCalculated(const int indice);

  // sobrecarga del operador <<
  template <class T>
  friend std::ostream& operator<<(std::ostream& os, const Fibonacci<T>& fibo);

 private:
  // Atributos de tipo base
  Type base1_;
  Type base2_;
  std::vector<Type> conjunto;
};

// cosntructores
// inicializamos los casos base
template <class Type>
Fibonacci<Type>::Fibonacci(const Type& val, const Type& val_2)
    : base1_(val), base2_(val_2), conjunto() {
  conjunto.push_back(base1_);
  conjunto.push_back(base2_);
}

// destructores
template <class Type>
Fibonacci<Type>::~Fibonacci() {}

// Operaciones
template <class Type>
bool Fibonacci<Type>::ItsCalculated(const int indice) {
  if (indice <= conjunto.size()) {
    return true;
  }
  return false;
}

template <class Type>
Type Fibonacci<Type>::Calcular(const int indice) {
  Type aux;
  if (ItsCalculated(indice)) return conjunto[indice - 1];
  aux = Calcular(indice - 2) + Calcular(indice - 1);
  conjunto.push_back(aux);
  return conjunto[indice - 1];
}

// sobrecarga del operador para escribir
template <class T>
std::ostream& operator<<(std::ostream& os, const Fibonacci<T>& fibo) {
  for (int i = 0; i < fibo.conjunto.size(); ++i) {
    os << "indice " << i << " = " << fibo.conjunto[i] << std::endl;
  }
  return os;
}

#endif