// Archivo fuente de la implementacion de la clase
#include "Estudiante.h"
#include "Materia.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor de la clase
Estudiante::Estudiante(const string &nombre, const string &cedula, int edad, float peso, float estatura)
{
    this -> nombre = nombre;
    this -> cedula = cedula;
    this -> edad = edad;
    this -> peso = peso;
    this -> estatura = estatura;  
}

// Este metodo incluye el objeto materia con el numero de semestre
// y crear una relacion nueva de EstudianteMateria dentro del estudiante
void Estudiante::incluirMateria(Materia *obj_materia, int num)
{
    EstudianteMateria *nuevo_objeto = new EstudianteMateria(obj_materia, num);

    if (nuevo_objeto != NULL)
    {
        materias.push_back(nuevo_objeto);
        cout << "\nIngreso exitoso de materia." << endl;
    }
    else
    {
        cout << "Hubo un problema al asignar la materia" << endl;
    }
}

// Getters

string Estudiante::getNombre()
{
    return this->nombre;
}

string Estudiante::getCedula()
{
    return this->cedula;
}

int Estudiante::getEdad()
{
    return this->edad;
}

float Estudiante::getEstatura()
{
    return this->estatura;
}

float Estudiante::getPeso()
{
    return this->peso;
}

vector<EstudianteMateria*> Estudiante::getVector()
{
    return this->materias;
}

// Setters

void Estudiante::setNombre(const string &nombre)
{
    this->nombre = nombre;
}

void Estudiante::setPeso(float peso)
{
    this->peso = peso;
}

void Estudiante::setEdad(int edad)
{
    this->edad = edad;
}

void Estudiante::setEstatura(float estatura)
{
    this->estatura = estatura;
}