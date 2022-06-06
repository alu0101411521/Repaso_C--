#include "fichero.h"

// constructores
Fichero::Fichero() {}

Fichero::Fichero(const std::filesystem::path& ruta) {
  ruta_ = ruta;
  nombre_ = ruta.filename().string();
  Abrir(ruta);
}

// metodos
void Fichero::Abrir(const std::filesystem::path& ruta) {
  texto_.clear();
  std::ifstream fichero(ruta.string());
  while (!fichero.eof()) {
    std::string texto;
    std::getline(fichero, texto);
    texto_.push_back(texto);
  }
  fichero.close();
}

void Fichero::Guardar() {
  std::ofstream fichero(ruta_.string());
  for (int i = 0; i < texto_.size(); ++i) {
    fichero << texto_[i] << std::endl;
  }
  fichero.close();
}


 

// metodos que devuelve el nombre del fichero
std::string Fichero::NombreFichero() const { return nombre_; }

Fichero Fichero::Introducir(std::vector<std::string>& cabecera) {
  // https://en.cppreference.com/w/cpp/container/vector
  // https://en.cppreference.com/w/cpp/container/vector/insert
  texto_.insert(texto_.begin(), cabecera.begin(), cabecera.end());
  return *this;
}

std::vector<std::string> Fichero::Contenido() const {
  std::vector<std::string> resultado;
  resultado = texto_;
  return resultado;
}

// sobrecarga de operadores
// os == ofstream en fichero
std::ostream& operator<<(std::ostream& os, const Fichero& fichero) {
  for (int i = 0; i < fichero.texto_.size(); i++) {
    os << fichero.texto_[i] << std::endl;
  }

  return os;
}

// is == ifstream en fichero
std::istream& operator>>(std::istream& is, Fichero& fichero) {
  while (!is.eof()) {
    std::string line;
    std::getline(is, line);
    fichero.texto_.push_back(line);
  }

  return is;
}