#include <iostream>
#include <string>
#include "../include/fibonacci.h"

int main() {
  Fibonacci<std::string> fibo("hola", "adios");
  std::cout << fibo.Calcular(3) << std::endl;
  std::cout << fibo << std::endl;
  std::cout  << std::endl;
  std::cout << "=========================" << std::endl;
  Fibonacci<int> fibo2(0, 1);
  std::cout << fibo2.Calcular(5) << std::endl;
  std::cout << fibo2 << std::endl;
  std::cout  << std::endl;
  std::cout << "=========================" << std::endl;

}