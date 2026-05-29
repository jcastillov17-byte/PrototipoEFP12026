#ifndef BODEGA_H
#define BODEGA_H
#include <iostream>
using std::string;


class bodega
{
    private:
		string id, tipoBodega, nombre, direccion, estado;
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
};

#endif // BODEGA_H
