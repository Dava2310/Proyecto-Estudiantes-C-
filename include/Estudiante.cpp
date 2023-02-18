// Archivo fuente de la implementacion de la clase
#include "Estudiante.h"
#include "Materia.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Estudiante::Estudiante(const string &nombre, const string &cedula, int edad, float peso, float estatura)
{
    this -> nombre = nombre;
    this -> cedula = cedula;
    this -> edad = edad;
    this -> peso = peso;
    this -> estatura = estatura;  
}

void Estudiante::listarNotas()
{
    cout << "\t\t LISTADO DE NOTAS COMPLETO DEL ESTUDIANTE: " << this->nombre << endl;
    for (int i = 0; i < materias.size(); i++)
    {	
        Materia* it = materias.at(i);
        cout << "Notas de la materia: " << it->getNombre() << " (" << it->getCodigo_Materia() << ")" << endl;
        cout << "Semestre de la materia: " << it->getNum_Semestre() << endl;
        cout << "Notas: ";

        // Vector temporal de las notas de la materia 
        vector<float> notas = it->getVector();

        // Recorrido de notas de la materia
        for (int j = 0; j < notas.size(); j++)
        {
            float it2 = notas[j];
            cout << it2 << " ";
        }
        cout << endl;

    };
}

void Estudiante::incluirMateria(Materia *obj_materia)
{
    // Incluir la materia dentro del vector "vector<Materia*> materias;"
    materias.push_back(obj_materia);
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

vector<Materia*> Estudiante::getVector()
{
    return this->materias;
}
