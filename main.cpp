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
#include <stdlib.h>

// Librerias de clases
#include "include/Materia.h"
#include "include/Estudiante.h"

using namespace std;

// Procedimientos y funciones del sistema
void crearEstudiante();
void registrarMateria(Estudiante *);
void listarNotas(Estudiante *);
void listarEstudiantes();
void listarMaterias(Estudiante *);
void menuEstudiantes(Estudiante *);
bool verificarCedula(const string cedula);
bool verificarMateria(Materia* obj_materia, Estudiante *obj_estudiante, int num);
Estudiante* encontrarEstudiante();
Materia* encontrarMateria(const string codigo);

void bordes(); // Para listar estudiante
void bordes2(); // Para listar materias
// NOTA: CREAR UN METODO PARA ELIMINAR LAS MEMORIAS DE LOS ESTUDIANTES

// Lista principal del sistema de estudiantes
vector<Estudiante*> listaEstudiantes;

// Lista principal del sistema para materias
vector<Materia*> listaMaterias;

int main()
{
    int opcion;
    int salir = 0;

	cout << "\t\tBIENVENIDO AL SISTEMA DE REGISTRO DE ESTUDIANTES, MATERIAS Y NOTAS." << endl;

    // Ciclo principal del sistema
    do{

		system("pause");
		system("cls");
        cout << "\t\t MENU PRINCIPAL DEL SISTEMA" << endl << endl;
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

void menuEstudiantes(Estudiante *obj_estudiante)
{
    /* Operaciones permitidas para un estudiante:

        1- Actualizar datos personales (por excepto de la cedula)
        2- Inscribir alguna materia
        3- Hacer el listado de notas del estudiante
    
    */

    int opcion;

    do{
    	system("pause");
		system("cls");
        cout << "\t\t MENU DE OPCIONES PARA EL ESTUDIANTE: " << obj_estudiante->getNombre() << " (C.I:" << obj_estudiante->getCedula() << ")" << endl << endl;
        cout << "1- Actualizar o cambiar datos personales (no aplica para la cedula)" << endl;
        cout << "2- Inscribir materia" << endl;
		cout << "3- Listar materias" << endl;
		cout << "4- Agregar notas a una materia" << endl;
        cout << "5- Listado de notas general del estudiante" << endl;
        cout << "6- Salir" << endl;
        cout << "Ingrese por favor una opcion del 1 al 6: ";
        cin >> opcion;

        switch(opcion)
        {
			case 1:
				break;
			case 2:
				registrarMateria(obj_estudiante);
				break;
			case 3:
				listarMaterias(obj_estudiante);
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				cout << "Ingrese una opcion valida entre el 1 y el 4" << endl;
        }

    }while(opcion != 6);
}

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
	system("cls");
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

	if (obj_estudiante == NULL)
	{
		cout << "Error con la creacion del estudiante." << endl;
		return;
	}

    // Asignar el estudiante al vector general de estudiantes
    listaEstudiantes.push_back(obj_estudiante);

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

void listarEstudiantes()
{	
	if (listaEstudiantes.size() < 1)
	{
		cout << "No hay estudiantes inscritos." << endl << endl;
		return;
	}

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

void registrarMateria(Estudiante *obj_estudiante)
{
	/*
		Para registrar una materia, se necesita el estudiante en especifico
		Crear el objeto materia
		Y asignarlo a su lista de materias
	*/

	// 1. Ya se tiene al estudiante conseguido por parametro

	// 2. Se asignan los datos a las variables
	// Variables necesarias:
	string nombre;
	string codigo_materia;
	int num_semestre;

	// Registro de esos datos
	system("cls");
	cout << "\t\t INGRESE A CONTINUACION LOS DATOS DE LA MATERIA: " << endl << endl;
	cout << "Codigo de la materia: "; cin >> codigo_materia;
	
	// Verificar que esta materia exista o no
	Materia *temp_materia = encontrarMateria(codigo_materia);

	if (temp_materia != NULL)
	{
		// Ingresar esta materia al estudiante
		char opcion = 'N';
		cout << "Se ha encontrado que esta materia existe. Con el nombre: " << temp_materia->getNombre() << endl;
		cout << "Desea inscribir esta materia? (Y/N): ";
		
		cin >> opcion;

		if (opcion == 'Y')
		{
			cout << "Ingrese el numero de semestre en el cual se cursa la materia: " << temp_materia->getNombre() << " (" << temp_materia->getCodigo_Materia() << ").";
			cin >> num_semestre;
			
			// Se debe verificar que no exista la misma materia 2 veces para el mismo semestre
			if (verificarMateria(temp_materia, obj_estudiante, num_semestre))
			{
				cout << "Se ha intentado ingresar la misma materia 2 veces para el mismo semestre." << endl;
				return;
			}

			obj_estudiante->incluirMateria(temp_materia, num_semestre);
			return;	
		}
		else
		{
			cout << "Se ha cancelado el proceso de registrar materia. La proxima vez, incluya un nuevo codigo." << endl;
			return;
		}
		
	}

	// Llegados aqui, significa que, la materia no ha sido encontrada, por tanto es nueva para el sistema
	cout << "Ingrese el nombre de la materia: ";
	cin.ignore();
	cin.clear();
	getline(cin, nombre);
	
	// Registrar materia en el sistema
	Materia *nuevaMateria = new Materia(nombre, codigo_materia);

	if (nuevaMateria == NULL)
	{
		cout << "Se ha producido un error intentando agregar esta materia al sistema." << endl;
		return;
	}

	listaMaterias.push_back(nuevaMateria);
	cout << "Se ha guardado los anteriores datos para una materia en el sistema." << endl;

	cout << "Ingrese el numero de semestre en el que se esta inscribiendo esta materia: ";
	cin >> num_semestre;

	// Hay que verificar si el estudiante tiene esta materia inscrita y en el mismo semestre
	if (verificarMateria(nuevaMateria, obj_estudiante, num_semestre))
	{
		cout << "Se ha intentado ingresar la misma materia 2 veces para el mismo semestre." << endl;
		return;
	}

	// Se asigna la materia al vector de materias del estudiante
	obj_estudiante->incluirMateria(nuevaMateria, num_semestre);
}

Materia* encontrarMateria(const string codigo)
{

	// Se busca encontrar una materia igual a la que se ha ingersado
	for (int i = 0; i < listaMaterias.size(); i++)
	{	
		// Si los codigos coinciden, devolver esta materia actual
		if (codigo == listaMaterias.at(i)->getCodigo_Materia())
		{
			return listaMaterias.at(i);
		}
	}

	return NULL;

}

bool verificarMateria(Materia* obj_materia, Estudiante *obj_estudiante, int num)
{
	// Se desea verificar si el estudiante ya tiene esta materia inscrita
	
	// Recorrer el vector de EstudianteMateria
	vector<EstudianteMateria*> lista = obj_estudiante->getVector();
	for (int i = 0; i < lista.size(); i++)
	{
		Materia* temp = lista.at(i)->getMateria();
		int numSemestre = lista.at(i)->getNum_Semestre();

		if (temp->getCodigo_Materia() == obj_materia->getCodigo_Materia() && 
			numSemestre == num)
		{
			// Esto significa que el codigo de la materia que se acaba de crear
			// Coincide con el codigo de una de las materias inscrita en su lista
			// Y ademas, sus numeros de semestres coinciden
			// De ser asi, se esta intentando ingresar la misma materia en el mismo semestre 2 veces

			return true;

		}

	}
	return false;
}

void listarMaterias(Estudiante *obj_estudiante)
{

	vector<EstudianteMateria*> list_materias = obj_estudiante->getVector();
	if (list_materias.size() < 1)
	{
		cout << "El estudiante no tiene materias inscritas." << endl;
		return;
	}

	cout << "\t\t LISTADO DE MATERIAS DEL ESTUDIANTE: " << obj_estudiante->getNombre() << " C.I:" << obj_estudiante->getCedula() << endl << endl;

	// Primer borde
	bordes2();

	// Centro con los titulos
	cout << "|";
	cout << "Nombre";
	for (int i = 0; i < 14; i++)
	{
		cout << " ";
	}
	cout << "|";
	cout << "Codigo de Materia";
	for (int i = 0; i < 2; i++)
	{
		cout << " ";
	}
	cout << "|";
	cout << "Num. del Semestre";
	for (int i = 0; i < 2; i++)
	{
		cout << " ";
	}
	cout << "|" << endl;

	// Segundo borde
	bordes2();

	// Recorrido e impresion de los datos de las materias
	for (int i = 0; i < list_materias.size(); i++)
	{
		Materia *temp = list_materias.at(i)->getMateria();

		string nombre = temp->getNombre();
		string codigo_materia = temp->getCodigo_Materia();
		int num_semestre = list_materias.at(i)->getNum_Semestre();

		// Impresion de los datos
		cout << "|";
		cout << nombre;
		for (int i = 0; i < 20 - nombre.length(); i++)
		{
			cout << " ";
		}
		cout << "|";

		cout << codigo_materia;

		for (int i = 0; i < 19 - codigo_materia.length(); i++)
		{
			cout << " ";
		}

		cout << "|";

		cout << num_semestre;
		
		int espacios = 1;
		if (num_semestre >= 10)
		{
			espacios = 2;
		}

		for (int i = 0; i < 19 - espacios; i++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}

	bordes2();

}

void listarNotas(Estudiante *obj_estudiante)
{

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

void bordes2()
{

	cout << "+";
	for (int i = 0; i < 20; i++)
	{
		cout << "-";
	}
	cout << "+";
	for (int i = 0; i < 19; i++)
	{
		cout << "-";
	}
	cout << "+";
	for (int i = 0; i < 19; i++)
	{
		cout << "-";
	}
	cout << "+" << endl;
}



