#include "EstudianteMateria.h"
#include "Materia.h"
#include "Nota.h"
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

void EstudianteMateria::incluirNota(float nota, string descripcion)
{
    // Crear el objeto nota:
    Nota *nueva_nota = new Nota(nota, descripcion);

    if (nueva_nota == NULL)
    {
        cout << "ERROR: No se pudo ingresar esta nota." << endl;
        return;
    }
    
    notas.push_back(nueva_nota);
}