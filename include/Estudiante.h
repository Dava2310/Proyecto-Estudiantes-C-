#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

using namespace std;

#include <string>
#include <vector>
#include "Materia.h"
#include "EstudianteMateria.h"
class Estudiante{

    // Atributos privados
    private:
        string nombre; // 20 caracteres 20 - 6 = 14
        string cedula; // 10 caracteres 10 - 6 = 4
        int edad; // 5 caracteres 5 - 4 = 1
        float estatura; // 9 caracteres 9 - 8 = 1
        float peso; // 6 caracteres 6 - 4 = 2
        vector<EstudianteMateria*> materias;

        // Nombre y Apellido  40 - 19 = 21

        //Metodos privados
    
    public:
        // Metodos de acceso publico
        // Constructor
        Estudiante(const string &nombre, const string &cedula, int edad, float peso, float estatura); //Constructor
        // Otros metodos
        void incluirMateria(Materia *obj_materia, int num);
        // Setters
        void setNombre(const string &nombre);
        // void setCedula(const string &cedula); NO DEBERIA ESTAR PERMITIDO DESPUES DE LA INICIALIZACION
        void setEdad(int edad);
        void setEstatura(float estatura);
        void setPeso(float peso);
        // Getters
        string getNombre();
        string getCedula(); 
        int getEdad();
        float getEstatura();
        float getPeso();
        vector<EstudianteMateria*> getVector();
};
#endif
