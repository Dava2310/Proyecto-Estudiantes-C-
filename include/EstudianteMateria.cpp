#include "EstudianteMateria.h"
#include "Materia.h"
#include "Nota.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor de la clase
EstudianteMateria::EstudianteMateria(Materia *obj_materia, int num)
{

    this->obj_materia = obj_materia;
    this->num_semestre = num;
    notas.clear();

}

// Incluye una nueva nota en la relacion de estudiante materia
void EstudianteMateria::incluirNota(float nota, string descripcion)
{
    // Crear el objeto nota:
    Nota *nueva_nota = new Nota(nota, descripcion);

    // Si no se pudo crear, retornar
    if (nueva_nota == NULL)
    {
        cout << "ERROR: No se pudo ingresar esta nota." << endl;
        return;
    }
    
    // Agregar la nueva nota a la lista de notas
    notas.push_back(nueva_nota);
    cout << "\nNota cargada con exito." << endl << endl;
}