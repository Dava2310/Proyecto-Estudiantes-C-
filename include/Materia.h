#ifndef MATERIA_H
#define MATERIA_H

using namespace std;

#include <string>
#include <vector>
class Materia
{

    // Atributos privados
    private:
        string nombre; // 20 caracteres - 6 = 14
        string codigo_materia;  

        // Codigo de Materia  19 - 17 = 2 
        // Num. del Semestre  19 - 17 = 2
        
    // Atributos publicos
    public:
        // Constructor
        Materia(const string &nombre, const string &codigo_materia); 
        // Getters
        string getNombre();
        string getCodigo_Materia();
        // Setters
        void setNombre(const string &nm) {this->nombre = nm;}
        
};

#endif
