#pragma once
#include <iostream>
#include <vector>

#include "celula.h"

class Tablero {
 public:
  // constructores
  Tablero();
  Tablero(int dim_heigth, int dim_width);

  // metodos
  void ModificarCeldaTablero(
      const Celula& celula_cambio);  // cambiar posiciones || cambiar estado
  
  Celula ObtenerCoordenadas(int pos_x, int pos_y);
  

  // getters
  int GetAncho();
  int GetAlto();

  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Tablero& tablero);
  
  
 private:
  int dim_heigth_;  // alto
  int dim_width_;   // ancho
  std::vector<std::vector<Celula>> tablero_;

  void GenerarTablero();

  // [0 # 0] -> cel.x = 0, cel.y = 1
  // [0 0 0]
  // [0 0 0]
};

// privada: Un metodo para poder Generar la matri de celulas
// Mostrar el tablero
// Modicar una celda del tablero
// Obtener una celda del tablero en funcion de las posiciones x,y
