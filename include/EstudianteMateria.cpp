#include "EstudianteMateria.h"
#include "Materia.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

EstudianteMateria::EstudianteMateria(Materia *obj_materia, int num)
{

    this->obj_materia = obj_materia;
    this->num_semestre = num;
    notas.clear();

}

void EstudianteMateria::incluirNota(float nota)
{
    notas.push_back(nota);
}