#ifndef NOTA_H
#define NOTA_H

using namespace std;

#include <string>

class Nota 
{
    // Atributos privados
    private:
        float puntuacion;
        string descripcionExamen;
    public:
        // Constructor
        Nota(float puntuacion, const string &descripcion);
        float getPuntuaction() {return this->puntuacion;}
        string getDescripcion() {return this->descripcionExamen;}
        void setPuntuacion(float puntos) {puntuacion = puntos;}
        void setDescripcion(string descripcion) {descripcionExamen = descripcion;}
};


#endif