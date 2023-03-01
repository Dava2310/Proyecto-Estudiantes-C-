#ifndef ESTUDIANTEMATERIA_H
#define ESTUDIANTEMATERIA_H

using namespace std;

#include "Materia.h"
#include "Nota.h"
#include <string>
#include <vector>

class EstudianteMateria 
{
    private:
        Materia *obj_materia;
        int num_semestre;
        vector<Nota *> notas;
    public:
        EstudianteMateria(Materia*, int);
        void incluirNota(float, string);
        void setNum_Semestre(int num) {this->num_semestre = num;}
        int getNum_Semestre() {return this->num_semestre;}
        Materia* getMateria() {return this->obj_materia;}
        vector<Nota *> getVectorNotas() {return this->notas;}
};  

#endif