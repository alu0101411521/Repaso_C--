#include "../include/tablero.h"

// constructores

Tablero::Tablero() {
  dim_heigth_ = 20;
  dim_width_ = 60;
  GenerarTablero();
}

Tablero::Tablero(int dim_heigth, int dim_width) {
  dim_heigth_ = dim_heigth;
  dim_width_ = dim_width;
  GenerarTablero();
}

// metodos

void Tablero::GenerarTablero() {
  // vector<vector<x>> -> filas(columnas(dato))
  tablero_.resize(dim_heigth_);
  for (int i = 0; i < dim_heigth_; ++i) {
    for (int j = 0; j < dim_width_; ++j) {
      tablero_[i].push_back(Celula(j, i));
    }
  }
}

void Tablero::ModificarCeldaTablero(const Celula& celula_cambio) {
  //   std::vector<std::vector<Celula>> tablero_;
  // tablero_[1][2] = celula_cambio;
  // Acceder a la posicion del tablero que quiero cambiar
  // Modificar el dato de esa posicion del tablero
  tablero_[celula_cambio.GetPositionY()][celula_cambio.GetPositionX()]
      .ChangeState(celula_cambio.GetState());
}

Celula Tablero::ObtenerCoordenadas(int pos_x, int pos_y) {
  Celula resultado;
  resultado = tablero_[pos_y][pos_x];
  return resultado;
}

// getters
int Tablero::GetAncho() { return dim_width_; }

int Tablero::GetAlto() { return dim_heigth_; }

// Sobrecarga de operadores
// '#' -> celula viva
// '0' -> celula muerta
std::ostream& operator<<(std::ostream& os, const Tablero& tablero) {
  for (int i = 0; i < tablero.dim_heigth_; ++i) {
    for (int j = 0; j < tablero.dim_width_; ++j) {
      if (tablero.tablero_[i][j].GetState() == true) {
        os << '-';
      } else {
        os << '#';
      }
    }
    os << std::endl;
  }
  return os;
}