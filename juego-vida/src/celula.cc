#include "../include/celula.h"

// constructores

Celula::Celula() {
  position_x_ = 0;
  position_y_ = 0;
  is_dead_ = true;
}

Celula::Celula(int position_x, int position_y, bool is_dead) {
  position_x_ = position_x;
  position_y_ = position_y;
  is_dead_ = is_dead;
}

// sobrecarga de operadores
std::ostream& operator<<(std::ostream& os, const Celula& celula1) {
  os << celula1.is_dead_ << " " << celula1.position_x_ << " "
     << celula1.position_y_;
  return os;
}

// metodos
void Celula::ChangePosition(int pos_x, int pos_y) {
  position_x_ = pos_x;
  position_y_ = pos_y;
}

void Celula::ChangeState(bool alive) { is_dead_ = alive; }

// getter
int Celula::GetPositionX() const { return position_x_; }

int Celula::GetPositionY() const { return position_y_; }

bool Celula::GetState() const { return is_dead_; }
