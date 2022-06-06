#include <iostream>

#include "../include/stack.h"

int main(){
  std::cout << "FUNCIONA\n";
  Stack_v_t<int> ejemplo;
  ejemplo.Insercion(4);
  ejemplo.Insercion(5);
  std::cout << ejemplo << std::endl; 
  std::cout << "========================" << std::endl;
  ejemplo.Extraccion();
  std::cout << ejemplo << std::endl; 
  std::cout << "========================" << std::endl;
  ejemplo.Top();
  std::cout << ejemplo << std::endl; 
  return 0;
}
