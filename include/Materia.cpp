#include "Materia.h"
#include <string>
using namespace std;

// Constructor de la clase
Materia::Materia(const string &nombre, const string &codigo_materia)
{
    this -> nombre = nombre;
    this -> codigo_materia = codigo_materia;
}

// Getters

string Materia::getNombre()
{
    return this->nombre;
}

string Materia::getCodigo_Materia()
{
    return this->codigo_materia;
}


