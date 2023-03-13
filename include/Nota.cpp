#include "Nota.h"
#include <string>
using namespace std;

// Constructor de la clase
Nota::Nota(float puntuacion, const string &descripcion)
{
    this->puntuacion = puntuacion;
    this->descripcionExamen = descripcion;
}
