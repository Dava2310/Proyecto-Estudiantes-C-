#include "Materia.h"
#include <string>
using namespace std;

Materia::Materia(const string &nombre, int num_semestre, const string &codigo_materia)
{
    this -> nombre = nombre;
    this -> codigo_materia = codigo_materia;
    this -> num_semestre = num_semestre;
}

void Materia::Agregar_Nota(float nota)
{
    // Agregar al vector de notas, la nota por parametro
    notas.push_back(nota);
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

int Materia::getNum_Semestre()
{
    return this->num_semestre;
}

vector<float> Materia::getVector()
{
    return this->notas;
}
