#include "persona.h"



  const char *Persona::getNombre() const {
      return nombre;
  }

  void Persona::cargarDesdeTeclado() {
      cout << "Nombre: ";
      cin.getline(nombre, 30);
      cout << "Apellido: ";
      cin.getline(apellido, 30);
      cout << "Direccion: ";
      cin.getline(direccion, 50);

      int cantidad;
      cout << "Cantidad de contactos: ";
      cin >> cantidad;
      cin.ignore();

      for (int i = 0; i < cantidad; ++i) {
          Contacto c;
          c.cargarDesdeTeclado();
          contactos.push_back(c);
      }
  }

  void Persona::mostrar() const {
      cout << "\n--- Persona ---\n";
      cout << "Nombre: " << nombre << "\n";
      cout << "Apellido: " << apellido << "\n";
      cout << "Direccion: " << direccion << "\n";
      cout << "Contactos:\n";
      for (const auto& c : contactos) {
          c.mostrar();
      }
  }

  void Persona::guardarBinario(ofstream &out) const {
      out.write(nombre, sizeof(nombre));
      out.write(apellido, sizeof(apellido));
      out.write(direccion, sizeof(direccion));
      int cantidad = contactos.size();
      out.write(reinterpret_cast<char*>(&cantidad), sizeof(int));
      for (const auto& c : contactos) {
          c.guardarBinario(out);
      }
  }

  void Persona::cargarBinario(ifstream &in) {
      in.read(nombre, sizeof(nombre));
      in.read(apellido, sizeof(apellido));
      in.read(direccion, sizeof(direccion));
      int cantidad = 0;
      in.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
      contactos.clear();
      for (int i = 0; i < cantidad; ++i) {
          Contacto c;
          c.cargarBinario(in);
          contactos.push_back(c);
      }
  }
