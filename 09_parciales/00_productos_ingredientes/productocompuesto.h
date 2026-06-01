#ifndef PRODUCTOCOMPUESTO_H
#define PRODUCTOCOMPUESTO_H

#include "producto.h"
// ProductoCompuesto
// Sus ingredientes son la unión de los ingredientes de sus
// subproductos. Relación "tiene-un" con punteros a Producto
// para poder contener tanto simples como compuestos (polimorfismo).
class ProductoCompuesto : public Producto {
private:
  Vector<Producto *> subproductos; // Composición polimórfica

public:
  ProductoCompuesto();

  ProductoCompuesto(int cod, const char *nom);

  // No libera los subproductos porque no son de su propiedad
  // (pueden vivir en otro contenedor).
  ~ProductoCompuesto() override;

  void agregarSubproducto(Producto *p);

  // Agrega a 'destino' los ingredientes de 'origen' sin duplicados
  static void fusionarSinDuplicados(Vector<Ingrediente> &destino,
                                    const Vector<Ingrediente> &origen);

  // Reúne recursivamente todos los ingredientes de los subproductos
  Vector<Ingrediente> getIngredientes() const override;

  // Muestra cada subproducto con sus propios ingredientes (indentado)
      void imprimirDetalle(ostream& os) const override;
};

#endif // PRODUCTOCOMPUESTO_H
