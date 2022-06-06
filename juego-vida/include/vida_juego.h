#pragma once
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <thread>
#include <vector>

#include "tablero.h"

class Juego {
 public:
  // constructores
  Juego();
  Juego(int dim_x, int dim_y, int num_celulas_vivas, std::vector<int> pos_x,
        std::vector<int> pos_y);

  // metodos para el auto mode
  void AutoMode(int n_celulas_vivas);

  // metodos para el sandbox
  void SandBox(int dim_x, int dim_y, int num_iteraciones, int num_celulas_vivas,
               std::vector<int> pos_x, std::vector<int> pos_y);

  // sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Juego& juego);
  friend int main();

 private:
  // atributos
  Tablero tablero_juego_;
  int num_celulas_;  // numero de celulas vivas
  std::vector<int> pos_x_;
  std::vector<int> pos_y_;
  std::vector<Celula> celulas_;

  // metodos para el juego (reglas)
  int CelulaVecina(Celula& celula);
  bool CelulaNace(Celula& celula_muerta);
  bool CelulaMuere(Celula& celula_viva);

  // funcion que devuelve n celulas en una posicion
  // random de un tablero por defecto
  std::vector<Celula> RandomPosition(int n_celulas_vivas);

  // funcion reglas en conjunto
  void Reglas(Tablero& copia_tablero);
};
