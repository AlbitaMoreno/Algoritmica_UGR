#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>
#include "Random.h"

using namespace std;
using namespace std::chrono;

/*********************************************************************************************/
/********************************************************************************************/
/*******************************************************************************************/

bool solucion = false;

/*********************************************************************************************/
/********************************************************************************************/
/*******************************************************************************************/

void ImprimirLaberinto(bool **lab, int tam);
bool HaySalida(int **&lab, int filFin, int colFin, int i , int j, bool **&camino);
bool en_limites(int fil, int col, int filFin, int colFin);
void InicializarLaberinto(int **lab, int N);
int tamanio(bool **lab, int tam);

/*********************************************************************************************/
/********************************************************************************************/
/*******************************************************************************************/

int main(){
	int n;
	cin >> n;

	bool **camino;											// Creamos la matriz del laberinto.
	camino = new bool*[n];
	
	for(int i = 0; i < n; i++){
		camino[i] = new bool [n];
	}
	

	int **laberinto = new int *[n];
	
	for(int i = 0; i < n; i++)
		laberinto[i] = new int [n];
	
	
	for(int i=0; i<n;i++){
		for(int h=0; h<n;h++){
			camino[i][h]=0;
			cin >> laberinto[i][h];
		}
	}
	
	//InicializarLaberinto(laberinto,n);
	
	int filFin = n - 1;
	int colFin = n -1;
	double temp;
	
	high_resolution_clock::time_point tantes, tdespues;
	duration<double> transcurrido;
	tantes = high_resolution_clock::now();
	
	bool existe_salida = HaySalida(laberinto, filFin,colFin,0,0,camino);
	
	tdespues = high_resolution_clock::now();
	transcurrido = duration_cast<duration<double>>(tdespues - tantes);
	  
	if(!existe_salida){
		cerr << "EL LABERINTO NO TIENE SOLUCION"  << endl;
		exit(1);
	}
	else{
		cerr << endl;
		cerr << "EL LABERINTO TIENE SOLUCION"  << endl;
		
		for(int i = 0; i < n; i++){
			for(int j= 0; j < n;j++){
				cerr << laberinto[i][j]<<" ";
			}
			cerr << endl;
		}
	
		cerr << endl;
		ImprimirLaberinto(camino, n);
		cerr << endl;
		cerr << "Tamaño del camino -->" << setw(4) << tamanio(camino,n) << endl;
		
		cout << n << " " << transcurrido.count() << endl;

	}
		
	return(0);
}

/*********************************************************************************************/
/********************************************************************************************/
/*******************************************************************************************/

bool HaySalida(int **&lab, int filFin, int colFin, int i , int j, bool **&camino){
	//Base-> llegas al final
	if(i == filFin && j == colFin){
		solucion = true;
		camino[i][j]=1;
	}
	else{
		lab[i][j] = 2;
			
		if(en_limites(i+1,j,filFin, colFin))
			if (lab[i+1][j] == 0 && !solucion){		//abajo			
				if(HaySalida(lab, filFin, colFin, i+1,j,camino))
					camino[i][j]=1;
			}
		
		if(en_limites(i,j+1,filFin, colFin))
			if(lab[i][j+1] == 0 && !solucion){ 		//derecha
				if(HaySalida(lab, filFin, colFin, i,j+1,camino))
					camino[i][j]=1;

			}
			
		if(en_limites(i-1,j,filFin, colFin))		
			if (lab[i-1][j] == 0 && !solucion){		//arriba 
				if(HaySalida(lab, filFin, colFin, i-1,j,camino))
					camino[i][j]=1;
			}
			
		if(en_limites(i,j-1,filFin, colFin))
			if (lab[i][j-1] == 0 && !solucion){ 	//izquierda
				if(HaySalida(lab, filFin, colFin, i,j-1,camino))
					camino[i][j]=1;
			}

	}
	
	return solucion;
}

/*********************************************************************************************/
/********************************************************************************************/
/*******************************************************************************************/

bool en_limites(int fil, int col, int filFin, int colFin){
	bool resultado=false;
	if(fil<=filFin && col<=colFin && col>=0 && fil>=0){
		resultado=true;
	}
	return resultado;
}

/*********************************************************************************************/
/********************************************************************************************/
/*******************************************************************************************/

void InicializarLaberinto(int **lab, int N){
	MyRandom generador(0,1);
	
	for(int i = 0; i < N; i++)
		for(int j=0; j<N; j++){
			lab[i][j] = generador.Next();
		}
		
	lab[0][0]=lab[N-1][N-1]=0;
}

/*********************************************************************************************/
/********************************************************************************************/
/*******************************************************************************************/

int tamanio(bool **lab, int tam){
	int resultado = 0;
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam; j++){
			if(lab[i][j]==1)
				resultado++;
		}
	}
	return resultado;
}

/*********************************************************************************************/
/********************************************************************************************/
/*******************************************************************************************/

void ImprimirLaberinto(bool **lab, int tam){		//Muestra por pantalla una matriz pasandole su tamaño.
	cerr << "Camino a seguir para salir del laberinto" << endl << endl;
	for(int i = 0; i<tam; i++){
		for(int j = 0; j<tam; j++){
			cerr << lab[i][j] << " ";
		}
		cerr << endl;
	}
}

