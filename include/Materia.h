#ifndef MATERIA_H
#define MATERIA_H

using namespace std;

#include <string>
#include <vector>
class Materia
{

    // Atributos privados
    private:
        string nombre;
        string codigo_materia;
        int num_semestre;
        vector<float> notas; 

    // Atributos publicos
    public:
        // Constructor
        Materia(const string &nombre, int num_semestre, const string &codigo_materia); 
        // Otros metodos
        void Agregar_Nota(float nota);
        // Getters
        string getNombre();
        string getCodigo_Materia();
        int getNum_Semestre();
        vector<float> getVector();

};

#endif
