/*
    Descripcion general del sistema:
        Este sistema permitirá crear en un principio estudiantes, con diferentes atributos dentro de sí
        Para cada uno de ellos, se podrán designar sus datos personales
        A su vez que para cada uno, se puede llevar un registro de las materias cursadas
        Y para cada una de las materias cursadas, se llevará un registro de las notas conseguidas
        Para al final, poder realizar reportes de los datos

	Integrantes:
	Crismar Morante, C.I 27802534
	Yulexis Campos, C.I 29843877
	Jessica Jiménez, C.I 27977142
	Fernando Márquez, C.I 30537460
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
#include "include/EstudianteMateria.h"
#include "include/Nota.h"

using namespace std;

// Procedimientos y funciones del sistema

// Operaciones para: Crear
void crearEstudiante();
void registrarMateria(Estudiante *);
void registrarNotas(Estudiante *);
void registrarNotas(Estudiante *, Materia *, int);

// Operaciones para: busqueda
Estudiante* encontrarEstudiante();
Materia* encontrarMateria(const string codigo);
EstudianteMateria *encontrarObjeto(Estudiante *, Materia *, int );

// Operaciones para: listar
void listarNotas(Estudiante *);
void listarEstudiantes();
void listarMaterias(Estudiante *);

// Operaciones de verificaciones:
bool verificarCedula(const string cedula);
bool verificarMateria(Materia* obj_materia, Estudiante *obj_estudiante, int num);

// Menu del sistema para estudiantes
void menuEstudiantes(Estudiante *);

// Agregados 
void bordes(); // Para listar estudiante
void bordes2(); // Para listar materias

// Estructuras de datos principales del sistema
vector<Estudiante*> listaEstudiantes;
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
		cout << endl;

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

    cout << "************MUCHAS GRACIAS POR USAR EL SISTEMA, HASTA LUEGO.***************" << endl;
    return 0;
}

// DEFINICION DE PROCEDIMIENTOS Y FUNCIONES

// ====================================== OPERACIONES PARA: CREAR ====================================
void crearEstudiante()
{
	system("cls");

    /*
        1- Recoger los datos necesarios para el estudiante
        2- Crear el objeto estudiante
        3- Asignarlo al vector general de estudiantes
    */

    // Variables de datos del estudiante
    string nombre, cedula;
    int edad;
    float peso, estatura;

    // 1- Recoleccion de datos
    cout << "\t\t INGRESE LOS DATOS DEL ESTUDIANTE A CONTINUACION: " << endl << endl;

	cout << "Cedula (Formato: 11222333): "; 
	cin >> cedula;
	
	// Hacer un checkeo de que nadie tenga esa cedula ingresada
	if (verificarCedula(cedula))
	{
		// Si encontro a alguien con la misma cedula, no se procede con el registro
		cout << "Se ha encontrado a un estudiante registrado con la misma cedula ingresada, por tanto, no se puede proceder." << endl;
		return;	
	}	

    cout << "Primer Nombre y Primer Apellido: "; 
	cin.ignore();
	getline(cin, nombre);
	
	cout << "Edad: "; cin >> edad;
	if (edad > 120 || edad < 0)
	{
		cout << "Es imposible ingresar a este estudiante con esta edad." << endl;
		return;
	}

    cout << "Peso(kg): "; cin >> peso;
	if (peso >= 1000 || peso < 0)
	{
		cout << "Es imposible ingresar a este estudiante con esta cantidad de Kilos" << endl;
		return;
	}

    cout << "Estatura(cm): "; cin >> estatura;
	if (estatura < 10 || estatura > 300) 
	{
		cout << "Es imposible ingresar a este estudiante con esta cantidad de altura." << endl;
		return;
	}

    // 2- Crear el objeto estudiante 
    Estudiante *obj_estudiante = new Estudiante(nombre, cedula, edad, peso, estatura);

	// Si el objeto estudiante no puede ser creado
	if (obj_estudiante == NULL)
	{
		cout << "Error con la creacion del estudiante." << endl;
		return;
	}

    // 3- Asignar el estudiante al vector general de estudiantes
    listaEstudiantes.push_back(obj_estudiante);

}

void registrarMateria(Estudiante *obj_estudiante)
{
	system("cls");

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
	cout << "\t\t INGRESE A CONTINUACION LOS DATOS DE LA MATERIA: " << endl << endl;
	cout << "Codigo de la materia: "; cin >> codigo_materia;
	
	// Verificar que esta materia exista o no
	Materia *temp_materia = encontrarMateria(codigo_materia);

	// En caso de que esta materia ya exista registrada en el sistema
	if (temp_materia != NULL)
	{
		// Ingresar esta materia al estudiante
		char opcion = 'N';
		cout << "Se ha encontrado que esta materia existe. Con el nombre: " << temp_materia->getNombre() << endl << endl;
		cout << "Desea inscribir esta materia? (Y/N): ";
		
		cin >> opcion;

		if (opcion == 'Y')
		{
			cout << "Ingrese el numero de semestre en el cual se cursa la materia: " << temp_materia->getNombre() << " (" << temp_materia->getCodigo_Materia() << "): ";
			cin >> num_semestre;
			
			if (num_semestre < 1)
			{
				cout << "El numero de semestre ingresado no puede ser menor a 1." << endl << endl;
				return;
			}

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
			cout << "Se ha cancelado el proceso de registrar materia." << endl;
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
	cout << "Se ha guardado los anteriores datos para una materia en el sistema." << endl << endl;

	cout << "Ingrese el numero de semestre en el que se esta inscribiendo esta materia: ";
	cin >> num_semestre;

	// Se asigna la materia al vector de materias del estudiante
	obj_estudiante->incluirMateria(nuevaMateria, num_semestre);
}

void registrarNotas(Estudiante *obj_estudiante)
{
	// Si el estudiante no tiene materias inscritas
	if (obj_estudiante->getVector().size() < 1)
	{
		return;
	}

	char opcion = 'Y';
	string codigo_materia = "";
	int num_semestre;

	// Inicia ciclo o periodo de agregar notas continuamente
	do {

		system("cls");

		// Se listan las materias inscritas para que el usuario pueda ver cual escoger
		listarMaterias(obj_estudiante);

		cout << "Ingrese el codigo de la materia a agregar notas: ";
		cin >> codigo_materia;

		cout << endl;

		cout << "Ingrese el numero de semestre: ";
		cin >> num_semestre;

		cout << endl;

		// Revisar si tiene una materia inscrita con este codigo de materia y numero de semestre
		
		// 1. Obteniendo la supuesta materia
		Materia *obj_materia = encontrarMateria(codigo_materia);

		bool verificacion = false;

		if (obj_materia == NULL)
		{	
			cout << "Codigo invalido de materia." << endl << endl;
		}
		else
		{
			// Si la materia existe, se verifica que la tenga el estudiante inscrita
			verificacion = verificarMateria(obj_materia, obj_estudiante, num_semestre);
			
			if (verificacion)
			{
				// En caso de ser cierta la verificacion, se entra a una segunda parte del periodo de registrar notas
				registrarNotas(obj_estudiante, obj_materia, num_semestre);
			}
			else
			{
				cout << "El estudiante no tiene esta materia inscrita." << endl << endl;
			}

		}
		
		cout << "\nDesea agregar notas a otra materia? (Y/N): ";
		cin >> opcion;

	}while(opcion == 'Y');
}

void registrarNotas(Estudiante *obj_estudiante, Materia *obj_materia, int num_semestre)
{

	while (true)
	{

		/*
			1. Una nota tiene que estar en el rango de 0 a 10
			2. Se muestran notdas las anteriores notas cargadas
			3. Se pide el valor de la nota 
			4. Se carga al vector de Notas
		*/

		// Encontrar el objeto EstudianteMateria
		EstudianteMateria *relacion = encontrarObjeto(obj_estudiante, obj_materia, num_semestre);

		if (relacion == NULL)
		{	
			cout << "ERROR AL AGREGAR NOTAS." << endl << endl;
			return;
		}
		
		// Se muestran las notas cargadas previamente
		if (relacion->getVectorNotas().size() > 0)
		{
			vector<Nota *> vectorNotas = relacion->getVectorNotas();
			
			cout << "\nNOTAS CARGADAS ANTERIORES: " << endl << endl;

			cout << "+------------------------------------------+----------------------+" << endl;
			cout << "|Descripcion del examen                    |Puntuacion            |" << endl;
			cout << "+------------------------------------------+----------------------+" << endl;
			
			// Recorriendo el vector de notas
			for (int j = 0; j < vectorNotas.size(); j++)
			{
				// Obteniendo la nota actual
				Nota *obj_nota = vectorNotas.at(j);

				// Obteniendo los valores a imprimir del objeto nota actual
				string descripcion = obj_nota->getDescripcion();
				float puntuacion = obj_nota->getPuntuaction();

				cout << "|";
				cout << descripcion;

				for (int z = 0; z < 42 - descripcion.length(); z++)
				{
					cout << " ";
				}
				cout << "|";
				
				printf ("%.2f", puntuacion);
				// Espacios: 22

				if (puntuacion == 10)
				{
					cout << "                 " << "|" << endl;
				}
				else
				{
					cout << "                  " << "|" << endl;
				}
			}
			cout << "+------------------------------------------+----------------------+" << endl;
			cout << endl;
		}
		else
		{
			cout << "No existen ninguna nota cargada previamente." << endl << endl;
		}

		// Pedir el valor de la nota: 
		float puntuacion; string descripcion;

		cout << "Ingrese la nota del examen: ";
		cin >> puntuacion;

		cout << "Ingrese la descripcion o nombre del examen: ";
		cin.ignore(); // Arreglar bug de ingreso: 
		getline(cin, descripcion);

		if (puntuacion >= 0 && puntuacion <= 10)
		{
			// Cargar el valor de la nota: 
			relacion->incluirNota(puntuacion, descripcion);
		}
		else
		{
			cout << "La nota debe estar en un rango de 0 a 10 pts." << endl;
		}
		

		cout << "Desea agregar otra nota (Y/N): ";
		char opcion;
		cin >> opcion;

		cout << endl;

		if (opcion != 'Y')
		{
			cout << "\nTerminando proceso de agregar notas a esta materia." << endl;
			return;
		}

	}

}

// ====================================== OPERACIONES PARA: BUSQUEDA ====================================

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

Materia* encontrarMateria(const string codigo)
{
	// Se busca encontrar una materia igual a la que se ha ingresado
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

EstudianteMateria *encontrarObjeto(Estudiante *obj_estudiante, Materia* obj_materia, int num_semestre)
{
	
	vector<EstudianteMateria*> lista = obj_estudiante->getVector();

	for (int i = 0; i < lista.size(); i++)
	{

		Materia *temp = lista.at(i)->getMateria(); 

		if (obj_materia->getCodigo_Materia() == temp->getCodigo_Materia() 
		&& num_semestre == lista.at(i)->getNum_Semestre())
		{
			return lista.at(i);
		}

	}

	return NULL;
}

// ====================================== OPERACIONES PARA: LISTAR ====================================

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
	cout << "Nombre y Apellido";
	for (int j = 0; j < 23; j++)
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
	cout << "    |" << endl;
	
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
		for (int j = 0; j < 40 - nombre.length(); j++)
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

		if (edad < 100)
		{
			cout << "   ";
		}
		else 
		{
			cout << "  ";
		}
		cout << "|";
		
		printf("%.2f", estatura);
		
		if (estatura >= 100)
		{
			cout << "   ";
		}
		else
		{
			cout << "    ";
		}
		
		cout << "|";
		
		printf("%4.2f", peso);
		if (peso < 10)
		{
			cout << "    |";
		}
		else if (peso >= 10 && peso < 100)
		{
			cout << "   |";
		}
		else if (peso >= 100)
		{
			cout << "  |";
		}


		cout << endl;
		
	}
	
	bordes();
	
}

void listarNotas(Estudiante *obj_estudiante)
{
	// Verificar el contenido de la lista de estudiantes
	// Si no hay estudiantes, no habra ninguna nota
	if (listaEstudiantes.size() < 1)
	{
		cout << "No hay estudiantes inscritos." << endl << endl;
	}

	// Obtener la lista de materias inscritas del estudiante
	vector<EstudianteMateria*> materiasInscritas = obj_estudiante->getVector();

	// Verificar si el estudiante tiene materias inscritas
	if (materiasInscritas.size() < 1)
	{
		cout << "El estudiante no tiene materias inscritas." << endl << endl;
	}

	cout << "\t\t LISTADO DE NOTAS COMPLETO DEL ESTUDIANTE: " << obj_estudiante->getNombre() << endl << endl;

	// Recorrer la lista de materias inscritas
	for (int i = 0; i < materiasInscritas.size(); i++)
	{	
		EstudianteMateria *materiaInscrita = materiasInscritas.at(i);

		Materia *obj_materia = materiaInscrita->getMateria();
		
		// Obteniendo la lista de notas de la materia inscrita
		vector<Nota*> notas = materiaInscrita->getVectorNotas();
		
		// Si no tiene notas asignadas, se continua a la siguiente materia
		if (notas.size() < 1)
		{
			continue;
		}

		cout << "\nNotas para la materia: " << obj_materia->getNombre() << " | Codigo: " << obj_materia->getCodigo_Materia() << endl << endl;
	
		cout << "+------------------------------------------+----------------------+" << endl;
		cout << "|Descripcion del examen                    |Puntuacion            |" << endl;
		cout << "+------------------------------------------+----------------------+" << endl;

		// Recorriendo el vector de notas
		for (int j = 0; j < notas.size(); j++)
		{
			// Obteniendo la nota actual
			Nota *obj_nota = notas.at(j);

			// Obteniendo los valores a imprimir del objeto nota actual
			string descripcion = obj_nota->getDescripcion();
			float puntuacion = obj_nota->getPuntuaction();

			cout << "|";
			cout << descripcion;

			for (int z = 0; z < 42 - descripcion.length(); z++)
			{
				cout << " ";
			}
			cout << "|";
			
			printf ("%.2f", puntuacion);
			// Espacios: 22

			if (puntuacion == 10)
			{
				cout << "                 " << "|" << endl;
			}
			else
			{
				cout << "                  " << "|" << endl;
			}

		}
		cout << "+------------------------------------------+----------------------+" << endl;

	}

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

// ====================================== OPERACIONES PARA: VERIFICAR ====================================

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

bool verificarMateria(Materia* obj_materia, Estudiante *obj_estudiante, int num)
{
	// Se desea verificar si el estudiante ya tiene esta materia inscrita
	
	// Recorrer el vector de EstudianteMateria que es basicamente las materias inscritas del estudiante junto a sus notas
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

// ====================================== MENU DEL SISTEMA DE ESTUDIANTE ====================================

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
        cout << "1- Inscribir materia" << endl;
		cout << "2- Listar materias" << endl;
		cout << "3- Agregar notas a una materia" << endl;
        cout << "4- Listado de notas general del estudiante" << endl;
        cout << "5- Salir" << endl;
        cout << "Ingrese por favor una opcion del 1 al 5: ";
        cin >> opcion;

		cout << endl;

        switch(opcion)
        {
			case 1:
				registrarMateria(obj_estudiante);
				break;
			case 2:
				listarMaterias(obj_estudiante);
				break;
			case 3:
				registrarNotas(obj_estudiante);
				break;
			case 4:
				listarNotas(obj_estudiante);
				break;
			case 5:
				cout << "Saliendo del menu de estudiante." << endl << endl;
				break;
			default:
				cout << "Ingrese una opcion valida entre el 1 y el 6" << endl;
        }

    }while(opcion != 5);

	cout << "\nSaliendo del menu de estudiantes." << endl << endl;
}

// ====================================== AGREGADOS ====================================

void bordes()
{
	cout << "+";
	for (int j = 0; j < 40; j++)
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
	for (int j = 0; j < 8; j++)
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



