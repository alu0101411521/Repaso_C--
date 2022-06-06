#include "../include/vida_juego.h"

// constructores
Juego::Juego() : tablero_juego_() {}

Juego::Juego(int dim_x, int dim_y, int num_celulas_vivas,
             std::vector<int> pos_x, std::vector<int> pos_y)
    : tablero_juego_(dim_x, dim_y) {
  num_celulas_ = num_celulas_vivas;

  for (int i = 0; i < num_celulas_vivas; ++i) {
    celulas_.push_back(Celula(pos_x[i], pos_y[i], false));
  }
  for (int i = 0; i < celulas_.size(); ++i) {
    tablero_juego_.ModificarCeldaTablero(celulas_[i]);
  }
}

// metodos para el juego (reglas)
/* x         y
   --------- 0
   ---123--- 1
   ---8*4--- 2
   ---765--- 3
*/

int Juego::CelulaVecina(Celula& celula) {
  int resultado{0};
  int x, y;

  x = celula.GetPositionX() - 1;
  y = celula.GetPositionY() - 1;
  if ((x >= 0 && x < tablero_juego_.GetAncho() &&
       (y >= 0 && y < tablero_juego_.GetAlto()))) {
    if (tablero_juego_.ObtenerCoordenadas(x, y).GetState() == false) {
      resultado += 1;
    }
  }

  x = celula.GetPositionX();
  y = celula.GetPositionY() - 1;
  if ((x >= 0 && x < tablero_juego_.GetAncho() &&
       (y >= 0 && y < tablero_juego_.GetAlto()))) {
    if (tablero_juego_.ObtenerCoordenadas(x, y).GetState() == false) {
      resultado += 1;
    }
  }

  x = celula.GetPositionX() + 1;
  y = celula.GetPositionY() - 1;
  if ((x >= 0 && x < tablero_juego_.GetAncho() &&
       (y >= 0 && y < tablero_juego_.GetAlto()))) {
    if (tablero_juego_.ObtenerCoordenadas(x, y).GetState() == false) {
      resultado += 1;
    }
  }

  x = celula.GetPositionX() - 1;
  y = celula.GetPositionY();
  if ((x >= 0 && x < tablero_juego_.GetAncho() &&
       (y >= 0 && y < tablero_juego_.GetAlto()))) {
    if (tablero_juego_.ObtenerCoordenadas(x, y).GetState() == false) {
      resultado += 1;
    }
  }

  x = celula.GetPositionX() + 1;
  y = celula.GetPositionY();
  if ((x >= 0 && x < tablero_juego_.GetAncho() &&
       (y >= 0 && y < tablero_juego_.GetAlto()))) {
    if (tablero_juego_.ObtenerCoordenadas(x, y).GetState() == false) {
      resultado += 1;
    }
  }

  x = celula.GetPositionX() - 1;
  y = celula.GetPositionY() + 1;
  if ((x >= 0 && x < tablero_juego_.GetAncho() &&
       (y >= 0 && y < tablero_juego_.GetAlto()))) {
    if (tablero_juego_.ObtenerCoordenadas(x, y).GetState() == false) {
      resultado += 1;
    }
  }

  x = celula.GetPositionX();
  y = celula.GetPositionY() + 1;
  if ((x >= 0 && x < tablero_juego_.GetAncho() &&
       (y >= 0 && y < tablero_juego_.GetAlto()))) {
    if (tablero_juego_.ObtenerCoordenadas(x, y).GetState() == false) {
      resultado += 1;
    }
  }

  x = celula.GetPositionX() + 1;
  y = celula.GetPositionY() + 1;
  if ((x >= 0 && x < tablero_juego_.GetAncho() &&
       (y >= 0 && y < tablero_juego_.GetAlto()))) {
    if (tablero_juego_.ObtenerCoordenadas(x, y).GetState() == false) {
      resultado += 1;
    }
  }
  return resultado;
}

bool Juego::CelulaNace(Celula& celula_muerta) {
  if (celula_muerta.GetState() == true) {
    if (CelulaVecina(celula_muerta) == 3) {
      celula_muerta.ChangeState(false);  // nace una celula
      return true;
    }
  }
  return false;
}

bool Juego::CelulaMuere(Celula& celula_viva) {
  if (celula_viva.GetState() == false) {
    if (CelulaVecina(celula_viva) != 2 && CelulaVecina(celula_viva) != 3) {
      celula_viva.ChangeState(true);  // muere una celula
      return true;
    }
  }
  return false;
}
// funcion reglas en conjunto
void Juego::Reglas(Tablero& copia_tablero) {
  copia_tablero = tablero_juego_;
  for (int i = 0; i < tablero_juego_.GetAlto(); ++i) {
    for (int j = 0; j < tablero_juego_.GetAncho(); ++j) {
      Celula aux = tablero_juego_.ObtenerCoordenadas(j, i);
      if (CelulaMuere(aux)) {
        copia_tablero.ModificarCeldaTablero(aux);
      } else if (CelulaNace(aux)) {
        copia_tablero.ModificarCeldaTablero(aux);
      }
    }
  }
}

// funcion que devuelve n celulas en una posicion random de un tablero por
// defecto

std::vector<Celula> Juego::RandomPosition(int n_celulas_vivas) {
  std::vector<Celula> celula_aleatorias;
  celula_aleatorias.resize(n_celulas_vivas);
  srand(time(0));
  for (int i = 0; i < celula_aleatorias.size(); ++i) {
    int x = rand() % (tablero_juego_.GetAncho() - 1);
    int y = rand() % (tablero_juego_.GetAlto() - 1);

    for (int i = 0; i < celula_aleatorias.size(); ++i) {
      while (celula_aleatorias[i].GetPositionX() == x &&
             celula_aleatorias[i].GetPositionY() == y) {
        x = rand() % (tablero_juego_.GetAncho() - 1);
        y = rand() % (tablero_juego_.GetAlto() - 1);
      }
    }
    //

    // Comprobar si existe una celula en esas posiciones
    celula_aleatorias[i].ChangePosition(x, y);
    celula_aleatorias[i].ChangeState(false);
  }

  // rand() % 10

  return celula_aleatorias;
}

// metodos para el auto mode
/*
    while () {
          1. Ejecutar logica
          2. Actualizar elementos del juego
          3. Mostrar elementos del juego
          4. Esperar un tiempo de 0'4s
    }
*/
void Juego::AutoMode(int n_celulas_vivas) {
  std::vector<Celula> auxiliar;
  auxiliar = RandomPosition(n_celulas_vivas);
  // modificar el tablero
  for (int i = 0; i < auxiliar.size(); ++i) {
    tablero_juego_.ModificarCeldaTablero(auxiliar[i]);
  }

  /*
  -**----
  --**---
  -------

  -*-----
  --**---
  -------
  */

  Tablero copia_tablero;
  while (true) {
    std::cout << tablero_juego_ << std::endl;
    Reglas(copia_tablero);
    tablero_juego_ = copia_tablero;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

// metodos para el sandbox
/*
  1.- Inicializamos el tablero
  2.- n celulas_vivas y sus posiciones
  3.- ejecutamos la logica
  4.- Solo mostraremos n veces el tablero ejecutandose
  5.- Esperar un tiempo de 0,8 seg.
*/
void Juego::SandBox(int dim_x, int dim_y, int num_iteraciones,
                    int num_celulas_vivas, std::vector<int> pos_x,
                    std::vector<int> pos_y) {
  int contador = pos_x.size();
  // 1.- Inicializamos el tablero
  Tablero copia_tablero_sb(dim_y, dim_x);

  // 2.- n celulas_vivas y sus posiciones
  for (int i = 0; i < contador; ++i) {
    copia_tablero_sb.ModificarCeldaTablero(Celula(pos_x[i], pos_y[i], false));
  }
  tablero_juego_ = copia_tablero_sb;

  //  4.- Solo mostraremos n veces el tablero ejecutandose
  while (num_iteraciones-- > 0) {
    // 5.- Esperar un tiempo de 0,8 seg.
    std::cout << tablero_juego_ << std::endl;
    Reglas(copia_tablero_sb);
    tablero_juego_ = copia_tablero_sb;
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
  }
}

// sobrecarga de operadores
std::ostream& operator<<(std::ostream& os, const Juego& juego) {
  os << juego.tablero_juego_;
  return os;
}