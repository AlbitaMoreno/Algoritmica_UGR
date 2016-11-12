/***************************************************************************/
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// 
//
// Minimizando el número de visitas al proveedor
// Fichero : proveedor.cpp
//
/***************************************************************************/


#include <iostream>
#include "Random.h"

using namespace std;

/******************************************************************************/
/*****************************************************************************/

typedef struct{
	int **datos;
	const int semanas = 4;
	const int dias = 7;
}Mes;

void CreaMes(Mes &mes);
void PintaMes(const Mes &mes,const char *msg);
void LiberaMes(Mes &mes);
int CalculoCapacidadMaxima(const Mes &mes);
void CalculaPlanning(const Mes &mes, Mes &planning, int r);

/******************************************************************************/
/*****************************************************************************/

//MAIN
int main(void){
	Mes mes;
	Mes planning;
	
	CreaMes(mes);
	PintaMes(mes, "Calendario de apertura de la tienda");
	
	int r = CalculoCapacidadMaxima(mes)+1;
	
	cout << "Capacidad máxima-> " << r << endl;

	CreaMes(planning);
	
	for(int i = 0; i < planning.semanas; i++)
		for(int j =0; j < planning.dias; j++)
			planning.datos[i][j] = 0;	//al principio no tengo que ir ningun dia
				
	CalculaPlanning(mes, planning, r);
			
	PintaMes(planning,"El plan de visitas al proveedor es-> ");
		
	cout << endl;
	
	LiberaMes(mes);
	return(0);
}


/******************************************************************************/
/*****************************************************************************/
/******************************************************************************/
/*****************************************************************************/
//FUNCIONES

void CreaMes(Mes &mes){
	MyRandom generador(0,1);	
	//Objeto que voy a usar para generar una matriz mes, que me dice los dias que habre o cierra la tienda
	mes.datos = new int *[mes.semanas];	
	//las filas son las semanas
	
	for(int i = 0; i < mes.semanas;i++)
		mes.datos[i] = new int [mes.dias];
	
	//Relleno el mes con:  0 y 1 
	//0 = cerrado	1 = abierto
	for(int semana = 0; semana < mes.semanas; semana++)
		for(int dia = 0; dia < mes.dias; dia++)
			mes.datos[semana][dia] = generador.Next();
	mes.datos[0][0] = 1;
}

void PintaMes(const Mes &mes,const char *msg){

	cout << msg << endl << endl;
	for(int semana = 0; semana < mes.semanas; semana++){
		for(int dia = 0; dia < mes.dias; dia++)
			cerr << " " << mes.datos[semana][dia];
		cout << endl;
	}
	cout << "******************************" << endl;
}

void LiberaMes(Mes &mes){
	for (int f = 0; f < mes.semanas; f++)
		delete [] mes.datos[f];
	
	// Liberar la memoria que ocupa el vector de punteros
	delete [] mes.datos;

}

int CalculoCapacidadMaxima(const Mes &mes){
	int capacidad;
	int maximo = 0;
	int aux = 0;
	int contador = 0;
	
	for(int semana = 0; semana < mes.semanas; semana++){
		for(int dia= 0 ; dia < mes.dias; dia++){
			
			if(mes.datos[semana][dia] == 0){	
			//compruebo si hay dias consecutivos que no abre
				contador++;
				aux = contador;
			}
			else{
				contador = 0;
				if(maximo < aux){
					maximo = aux;					
				}
			}
				
		}
	}
	return(maximo);
}


void CalculaPlanning(const Mes &mes, Mes &planning, int r){
	
	for(int semana = 0; semana < mes.semanas; semana++){
		for(int dia = 0; dia < mes.dias; dia++){
			r--;
			
			if(r == 0 && mes.datos[semana][dia] == 1){
				r = CalculoCapacidadMaxima(mes)+1;
				planning.datos[semana][dia] = 1;
			}
			
			else{
				if(r == 0 && mes.datos[semana][dia] != 1){	//
					// si el lunes abre me planteo recorrer todos los dias de la semana hacia atras
					if(mes.datos[semana][0] == 1){
					
						while(mes.datos[semana][dia] != 1){
							dia--;	//retrocedo hasta encontrar un dia que abra
							
						}
					
						if(r == 0 && mes.datos[semana][dia] == 1){
							r = CalculoCapacidadMaxima(mes)+1;
							planning.datos[semana][dia] = 1;
						}
					}
					else{
						if(mes.datos[semana-1][0] ==1){
							while(mes.datos[semana][dia] != 1){
								dia--;	//retrocedo hasta encontrar un dia que abra
								if(dia == 0 && mes.datos[semana][dia] != 1){
									semana--;
									dia = 6;								
								}
							}
						
						
						}				
					}
				}
			}
		}
	}
}


