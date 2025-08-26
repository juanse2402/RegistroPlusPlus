#include "stdafx.h"
#include "menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <limits>

using namespace std;

// Implementación de funciones
void mostrarMenu(){ 
	system("cls");

	int accion;

	cout << "========== REGISTRO++ =========" << endl;
	cout << "Software de Registro de operaciones comerciales" << endl;
	cout << "Version 0.01 - 26-08-2025" << endl;
	cout << endl;
	cout << "1. Registrar Operacion" << endl;
	cout << "2. Leer memoria" << endl;
	cout << "3. Salir" << endl;
	cout << endl;
	cout << "ACCION: ";

	cin >> accion;

	switch (accion){
	case 1:
		registrarOperacion();
		break;
	case 2:
		leerMemoria();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "OPCION INCORRECTA!!!" << endl;
		break;
	
	}

}

void registrarOperacion(){ 

	string nombre, producto, precio, pago;
	
	
	ofstream archivo("memoria.txt", ios::app);
	
	cout << "CLIENTE: " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer
	getline(cin, nombre);
	cout << "PRODUCTO: " << endl;
	getline(cin, producto);
	cout << "PRECIO: " << endl;
	getline(cin, precio);
	cout << "PAGO: " << endl;
	getline(cin, pago);
	//fecha y hora
	time_t t = time(0); // tiempo actual en segundos
	tm* ahora = localtime(&t);
	
	archivo << "======================" << endl;
	archivo << "Nombre: " + nombre << endl;
	archivo << "Producto: " + producto << endl;
	archivo << "Precio: " + precio << endl;
	archivo << "Pago: " + pago << endl;
	archivo << "Fecha y hora: "
        << ahora->tm_mday << "/"
        << (ahora->tm_mon + 1) << "/"
        << (ahora->tm_year + 1900) << " "
        << ahora->tm_hour << ":"
        << ahora->tm_min << ":"
        << ahora->tm_sec << endl;
	archivo << "======================" << endl;
	return;

}

void leerMemoria(){ 
		ifstream archivoLectura("memoria.txt");

        if (!archivoLectura.is_open()) {
            cout << "No se pudo abrir el archivo." << endl;
			return;
        }

        string linea;
        cout << "\n=== Contenido de memoria.txt ===" << endl;
        while (getline(archivoLectura, linea)) {
            cout << linea << endl;
        }

        archivoLectura.close();
        cout << "\nPresiona ENTER para salir...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get(); // esto sí espera ENTER

}
