/*
    Descripcion general del sistema:
        Este sistema permitirá crear en un principio estudiantes, con diferentes atributos dentro de sí
        Para cada uno de ellos, se podrán designar sus datos personales
        A su vez que para cada uno, se puede llevar un registro de las materias cursadas
        Y para cada una de las materias cursadas, se llevará un registro de las notas conseguidas
        Para al final, poder realizar diferentes operaciones como reportes que permitan visualizar los datos guardados
*/

// Librerias de uso estandar
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// Librerias de clases
#include "include/Materia.h"
#include "include/Estudiante.h"

using namespace std;

// Procedimientos y funciones del sistema
void crearEstudiante();
void registrarMateria();
void listarNotas();
void listarEstudiantes();
void menuEstudiantes(Estudiante *obj_estudiante);
bool verificarCedula(const string cedula);
Estudiante* encontrarEstudiante();
void bordes();
// NOTA: CREAR UN METODO PARA ELIMINAR LAS MEMORIAS DE LOS ESTUDIANTES

// Lista principal del sistema de estudiantes
vector<Estudiante*> listaEstudiantes;

int main()
{
    int opcion;
    int salir = 0;
    // Ciclo principal del sistema
    do{
		
        cout << "\t\t MENU PRINCIPAL DEL SISTEMA" << endl;
        cout << "1- Crear un estudiante" << endl;
        cout << "2- Acceder a las operaciones de estudiantes " << endl;
        cout << "3- Listar estudiantes" << endl;
        cout << "4- Salir" << endl;
        cout << "Ingrese una opcion valida del 1 al 3: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                crearEstudiante();
                break;
            case 2:
                // Para este caso, se debe encontrar a un estudiante, y despues colocarlo por parametro al menu de estudiantes
				
				Estudiante *obj_estudiante; 
				obj_estudiante = encontrarEstudiante();
				
				if (obj_estudiante != NULL)
				{
					menuEstudiantes(obj_estudiante);					
				}
				
                break;
            case 3:
				listarEstudiantes();
				break;
            case 4:
                cout << "Esta seguro de salir? Todos los datos se borraran" << endl;
                cout << "Ingrese 1 para salir, ingrese cualquier otro numero para no salir" << endl;
                cin >> salir;
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
        }

    }while(salir != 1);

    cout << "MUCHAS GRACIAS POR USAR EL SISTEMA, HASTA LUEGO" << endl;
    return 0;
}

// DEFINICION DE PROCEDIMIENTOS Y FUNCIONES
void crearEstudiante()
{
    /*
        1- Recoger los datos necesarios para el estudiante
        2- Crear el objeto estudiante
        3- Asignarlo al vector general de estudiantes
    */

    // Variables de datos del estudiante
    string nombre, cedula;
    int edad;
    float peso, estatura;

    // Recoleccion de datos
    cout << "\t\t INGRESE LOS DATOS DEL ESTUDIANTE A CONTINUACION: " << endl;
    cout << "Nombre: "; cin >> nombre;
    cout << "Cedula: "; cin >> cedula;
    
	// Hacer un checkeo de que nadie tenga esa cedula ingresada
	if (verificarCedula(cedula))
	{
		// Si encontro a alguien con la misma cedula, no se procede con el registro
		cout << "Se ha encontrado a un estudiante registrado con la misma cedula ingresada, por tanto, no se puede proceder." << endl;
		return;	
	}	
	cout << "Edad: "; cin >> edad;
    cout << "Peso: "; cin >> peso;
    cout << "Estatura: "; cin >> estatura;

    // Crear el objeto estudiante con uso de memoria de manera explicita
    Estudiante *obj_estudiante = new Estudiante(nombre, cedula, edad, peso, estatura);

    // Asignar el estudiante al vector general de estudiantes
    listaEstudiantes.push_back(obj_estudiante);

}

void menuEstudiantes(Estudiante *obj_estudiante)
{
    /* Operaciones permitidas para un estudiante:

        1- Actualizar datos personales (por excepto de la cedula)
        2- Inscribir alguna materia
        3- Hacer el listado de notas del estudiante
    
    */

    int opcion;

    do{
    	//clrscr();
        cout << "\t\t MENU DE OPCIONES PARA EL ESTUDIANTE: " << obj_estudiante->getNombre() << "(" << obj_estudiante->getCedula() << ")" << endl;
        cout << "1- Actualizar o cambiar datos personales (no aplica para la cedula)" << endl;
        cout << "2- Inscribir materia" << endl;
        cout << "3- Listado de notas del estudiante" << endl;
        cout << "4- Salir" << endl;
        cout << "Ingrese por favor una opcion del 1 al 4: ";
        cin >> opcion;

        switch(opcion)
        {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				cout << "Ingrese una opcion valida entre el 1 y el 4" << endl;
        }

    }while(opcion != 4);
}

Estudiante* encontrarEstudiante()
{
	Estudiante* obj_estudiante = NULL;
	Estudiante* temporal;
	int encontrado = 0;
	string cedula;
	// Se hara el proceso para encontrar un estudiante segun la cedula
	
	//clrscr();
	cout << "Ingrese la cedula del estudiante a manipular: ";
	cin >> cedula;
	
	// Busqueda
	for (int i = 0; i < listaEstudiantes.size() && encontrado == 0; i++)
	{
		temporal = listaEstudiantes[i];
		if (temporal->getCedula() == cedula)
		{
			encontrado = 1;
			obj_estudiante = temporal;
		}
		
	}
	
	if (encontrado == 0)
	{
		cout << "Estudiante con cedula: " << cedula << " no encontrado." << endl;
	}
	
	return obj_estudiante;
}

void registrarMateria()
{
	
}

void listarNotas()
{

}

// Procedimiento para listar estudiantes
void listarEstudiantes()
{
	// Se debe hacer uso y recorrido del vector (variable global) lista de estudiantes
	//clrscr();
	cout << "\t\t LISTADO DE ESTUDIANTES " << endl << endl;
	
	// Primer borde
	bordes();
	
	// Centro con los titulos
	cout << "|";
	cout << "Nombre";
	for (int j = 0; j < 14; j++)
	{
		cout << " ";
	
	}
	cout << "|";
	cout << "Cedula";
	for (int j = 0; j < 4; j++)
	{
		cout << " ";
	}
	cout << "|";
	cout << "Edad";
	cout << " ";
	cout << "|";
	cout << "Estatura";
	cout << " ";
	cout << "|";
	cout << "Peso";
	cout << "  |" << endl;
	
	// Segundo borde 
	bordes();
	
	for (int i = 0; i < listaEstudiantes.size(); i++)
	{
		Estudiante* obj_estudiante = listaEstudiantes[i];
		
		string nombre = obj_estudiante->getNombre();
		string cedula = obj_estudiante->getCedula();
		int edad = obj_estudiante->getEdad();
		float estatura = obj_estudiante->getEstatura();
		float peso = obj_estudiante->getPeso();
		
		// Impresion de los resultados
		cout << "|";
		cout << nombre;
		for (int j = 0; j < 20 - nombre.length(); j++)
		{
			cout << " ";
			
		}
		cout << "|";
		
		cout << cedula;
		for (int j = 0; j < 10 - cedula.length(); j++)
		{
			cout << " ";
			
		}
		cout << "|";
		
		cout << edad;
		for (int j = 0; j < 3; j++)
		{
			cout << " ";
			
		}
		cout << "|";
		
		printf("%5.2f", estatura);
		cout << "   ";
		cout << "|";
		
		printf("%4.2f", peso);
		cout << " |";
		cout << endl;
		
	}
	
	bordes();
	
}

void bordes()
{
	cout << "+";
		for (int j = 0; j < 20; j++)
		{
			cout << "-";
		}
		cout << "+";
		for (int j = 0; j < 10; j++)
		{
			cout << "-";
		}
		cout << "+";
		for (int j = 0; j < 5; j++)
		{
			cout << "-";
		}
		cout << "+";
		for (int j = 0; j < 9; j++)
		{
			cout << "-";
		}
		cout << "+";
		for (int j = 0; j < 6; j++)
		{
			cout << "-";
		}
		cout << "+" << endl;
}

bool verificarCedula(const string cedula)
{
	Estudiante* temporal;
	// Busqueda
	int encontrado = 0;
	for (int i = 0; i < listaEstudiantes.size() && encontrado == 0; i++)
	{
		temporal = listaEstudiantes[i];
		if (temporal->getCedula() == cedula)
		{
			encontrado = 1;
			return true;
		}
	}
	
	return false;
	
}
