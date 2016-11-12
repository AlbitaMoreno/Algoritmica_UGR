#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

bool solucion = false;

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

void ImprimirLaberinto(bool **lab, int tam){		//Muestra por pantalla una matriz pasandole su tamaño.
	for(int i = 0; i<tam; i++){
		for(int j=0; j<tam; j++){
			cout<<lab[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool en_limites(int fil, int col, int filFin, int colFin){
	bool resultado=false;
	if(fil<=filFin && col<=colFin && col>=0 && fil>=0){
		resultado=true;
	}
	return resultado;
}



bool HaySalida(int **&lab, int filFin, int colFin, int i , int j, bool **&camino){

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
		
		
		if(en_limites(i,j-1,filFin, colFin))
		if (lab[i][j-1] == 0 && !solucion){ 	//izquierda
			if(HaySalida(lab, filFin, colFin, i,j-1,camino))
				camino[i][j]=1;
		}

		
		if(en_limites(i-1,j,filFin, colFin))		
		if (lab[i-1][j] == 0 && !solucion){		//arriba 
			if(HaySalida(lab, filFin, colFin, i-1,j,camino))
				camino[i][j]=1;
		}

	}
	return solucion;
}

int main(){	
	int n;
	cin>>n;




	bool **camino;											// Creamos la matriz del laberinto.
	camino = new bool*[n];
	for(int i = 0; i<n; i++){
		camino[i] = new bool[n];
	}


	int **laberinto = new int *[n];
	
	for(int i = 0; i < n; i++)
		laberinto[i] = new int [n];
		
	for(int i=0; i<n;i++)
		for(int h=0; h<n;h++){
			camino[i][h]=0;
			cin >> laberinto[i][h];
		}
	
	
	int filFin = n - 1;
	int colFin = n -1;
	
		for(int i = 0; i < n; i++){
			for(int j= 0; j < n;j++){
				cout<<laberinto[i][j]<<" ";
		}
	cout<<endl;
	}
	
	
	int f_inicio = 0;
	int c_inicio = 0;

	
	bool existe_salida = HaySalida(laberinto, filFin,colFin, f_inicio,c_inicio,camino);
	
	if(!existe_salida){
		cerr << "EL LABERINTO NO TIENE SOLUCION"  << endl;

	}else
	cerr << "EL LABERINTO TIENE SOLUCION"  << endl;
		
		for(int i = 0; i < n; i++){
			for(int j= 0; j < n;j++){
				cout<<laberinto[i][j]<<" ";

		}
	cout<<endl;

	}

	cout<<endl;


	ImprimirLaberinto(camino, n);

	cout<<"Tamaño del camino= "<<tamanio(camino,n)<<endl;

	
		
	return(0);
}

