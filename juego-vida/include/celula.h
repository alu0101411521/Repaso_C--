#pragma once
#include <iostream>

class Celula {
 public:
  // constructores
  Celula();
  Celula(int position_x, int position_y, bool is_dead = true);

  // metodos
  void ChangePosition(int pos_x, int pos_y);
  void ChangeState(bool alive);

  // getter
  int GetPositionX() const;
  int GetPositionY() const;
  bool GetState() const;

  // sobrecarga del operador ostream
  friend std::ostream& operator<<(std::ostream& os, const Celula& celula1);

 private:
  // int cel_alive_;
  bool is_dead_;    // celula muerta o celula viva
  int position_x_;  // posicion de la celula x
  int position_y_;  // posicion de la celula y
};

// Tienes que poder crear una por defecto OK
// Tienes que poder crear una con una posicion OK
// Tienes que poder mostrar la celula por pantalla OK
// Tienes que poder modificar la posicion de la celula OK
// Tienes que poder modificar si la celula esta muerta o no OK

// Tiene que poder obtener el estado de la celula
// Tiene que poder obtene la posicion de la celula