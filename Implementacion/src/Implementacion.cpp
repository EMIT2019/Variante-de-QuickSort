//============================================================================
// Name        : Implementacion.cpp
// Author      : EMIT
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct persona {
	string nombre;
	int edad;
}datos[5];





void ordenandoPersonas(struct persona *datos, int init, int end){
	int i = init, j = end;
	int tempAge;
	string tempName;
	int pivote = datos[(i + j) / 2].edad;

	while(i <= j){
			while(datos[i].edad < pivote){
				i++;
			};

			while(datos[j].edad > pivote){
				j--;
			};

			if(i <= j){
				tempAge = datos[i].edad;
				datos[i].edad = datos[j].edad;
				datos[j].edad = tempAge;

				tempName = datos[i].nombre;
				datos[i].nombre = datos[j].nombre;
				datos[j].nombre = tempName;

				i++;
				j--;
			};
		}

		if(init < j){
			ordenandoPersonas(datos, init, j);
		};

		if(i < end){
			ordenandoPersonas(datos, i, end);
		};

}

void ingresarPersona(){

	cout<<"Ingrese el nombre de una persona y acontinuacion ingrese una edad para esa persona."<<endl;

	for(int x = 0; x < 5; x++){
		cout<<"Nombre de persona numero "<<x+1<<": "<<endl;
		cin>>datos[x].nombre;
		cout<<"Edad de persona numero "<<x+1<<": "<<endl;
		cin>>datos[x].edad;
	};

}

int main() {
	int ini = 0, fin = 5;
	ingresarPersona();

	cout<<"Personas sin ordenar."<<endl;
	for(int x = 0; x < 5; x++){
		cout<<datos[x].nombre<<" - "<<datos[x].edad<<endl;
	}

	ordenandoPersonas(datos, ini, fin);

	cout<<"\nPersonas ordenadas."<<endl;
	for(int x = 0; x < 5; x++){
		cout<<datos[x].nombre<<" - "<<datos[x].edad<<endl;
	}

	return 0;
}
