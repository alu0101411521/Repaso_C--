#include "parseador.h"

// constructores
Parseador::Parseador() {}

void Parseador::Parsear(const std::filesystem::path& ruta_entrada,
                        const std::filesystem::path& ruta_cabezera) {
  // https://en.cppreference.com/w/cpp/filesystem/directory_iterator
  // https://en.cppreference.com/w/cpp/filesystem/is_directory

  // Comprobar si ruta_entrada es un directorio
  if (std::filesystem::is_directory(ruta_entrada)) {
    // Iterar sobre el directorio
    for (const std::filesystem::directory_entry& dir_entry :
         std::filesystem::directory_iterator{ruta_entrada}) {
      if (!std::filesystem::is_directory(dir_entry)) {
        // Si es un archivo modificarlo
        Fichero fichero(dir_entry.path());
        Fichero fichero_cabezera(ruta_cabezera);
        // modificar contenido_cabezera cambiando las palabras claves
        std::vector<std::string> cabecera = Sustituir(fichero_cabezera, fichero);
        // insertarlo al principio del fichero
        fichero.Introducir(cabecera);
        // guardar fichero
        fichero.Guardar();
      }
    }
  } else {
    // Si es un fichero
    Fichero fichero(ruta_entrada);
    Fichero fichero_cabezera(ruta_cabezera);
    // Abrirlo y modificarlo
    std::vector<std::string> cabecera = Sustituir(fichero_cabezera, fichero);
    fichero.Introducir(cabecera);
    // Guardarlo
    fichero.Guardar();
  }
}

// Tarea para hacer miercoles

std::vector<std::string> Parseador::Sustituir(const Fichero& fichero, const Fichero& fichero_entry) {
  // https://en.cppreference.com/w/cpp/regex
  // https://en.cppreference.com/w/cpp/regex/regex_replace
  // gurdamos el vector de strings de cabecera
  // std::regex_replace(text, vowel_re, "pepe")
  std::vector<std::string> contenido_cabecera = fichero.Contenido();
  std::regex current_date_regex("\\$\\{current_date\\}");
  std::regex current_file_regex("\\$\\{current_file\\}");
  Fecha fecha = CurrentDate();
  std::string fecha_str = fecha.ToString();
  std::string file_str = CurrentFile(fichero_entry);
  for (int i = 0; i < contenido_cabecera.size(); ++i) {
    contenido_cabecera[i] = std::regex_replace(contenido_cabecera[i],
                                               current_date_regex, fecha_str);
    contenido_cabecera[i] =
        std::regex_replace(contenido_cabecera[i], current_file_regex, file_str);
  }

  return contenido_cabecera;
}

// metodos privados
Fecha Parseador::CurrentDate() { return Fecha(); }

std::string Parseador::CurrentFile(const Fichero& fichero) {
  return fichero.NombreFichero();
}