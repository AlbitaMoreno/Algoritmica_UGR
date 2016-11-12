/***************************************************************************/
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// 
//
// Minimizando el número de visitas al proveedor
// Fichero : TSM1.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


int main(int argc, char *argv[]){

	if(argc < 2){
		cout <<"Falta fichero de entrada\n";
		return -1;
	}

	string comentario;
	ifstream fentrada;
	//ofstream fsalida;
	
	int n_ciudades;
	fentrada.open(argv[1]);
	fentrada >> comentario;
	fentrada >> n_ciudades;
	
	double ciudad[n_ciudades][2];
	
	for(int i = 0; i < n_ciudades; i++){
		fentrada >> comentario;
		fentrada >> ciudad[i][0];
		fentrada >> ciudad[i][1];
	}


	fentrada.close();

	double distancias[n_ciudades][n_ciudades];
	
	for(int i = 0; i < n_ciudades; i++)
		for(int j = 0;j < n_ciudades;j++)
			distancias[i][j] = sqrt(pow(ciudad[i][0]-ciudad[j][0],2)+pow(ciudad[i][1]-ciudad[j][1],2));

	int solucion[n_ciudades];
	bool candidatos[n_ciudades];
	
	//Inicializamos el vector solucion a -1
	//Ponemos todos los candidatos a true (disponibles)
	
	for(int i = 0; i < n_ciudades; i++){
		solucion[i] = -1;
		candidatos[i] = true;
	}
	
	
	bool vacio = true;

	int solucion_final[n_ciudades];
	int distancia_min;

	for(int k = 0;k < n_ciudades; k++){
	
	//Realizamos el algoritmo empezando por todas las ciudades
	//Metemos la primera ciudad en solución y la quitamos de candidatos
		int cont = 0;
		solucion[cont] = k;
		candidatos[k] = false;
		cont++;

		for(int i = 0; i < n_ciudades;i ++)
			if(candidatos[i] == true)
				vacio = false;


		//Mientras queden ciudades en candidatos
		while(!vacio){
			
			bool encontrado = false;
			//cogemos la distancia minima la de la primera ciudad
			double dist_min = distancias[solucion[cont-1]][0];
			int min = 0;
			//mientras que la ciudad no este disponible en candidatos y no sea ella misma seguimos buscando
			while(!encontrado){
				if(candidatos[min] && dist_min != 0)
					encontrado = true;
					
				else{
					min++;
					dist_min=distancias[solucion[cont-1]][min];
				}
			}
			
			//Ahora que tenemos una distancia disponible buscamos la minima
			for(int i = min + 1; i < n_ciudades; i++)
				if(distancias[solucion[cont-1]][i] < dist_min && candidatos[i] && distancias[solucion[cont-1]][i]!=0){
					min = i;
					dist_min = distancias[solucion[cont-1]][i];
				}
				
			//metemos la ciudad mínima en solución y la quitamos de candidatos
			candidatos[min] = false;
			solucion[cont] = min;
			cont++;
		
			
			vacio = true;
			
			for(int i = 0; i < n_ciudades; i++)
				if(candidatos[i] == true)
				vacio = false;
		}

		//calculamos distancia de la solución obtenida
		int suma = 0;

		for(int i = 0; i < n_ciudades; i++){
			int n1 = solucion[i];
			int n2 = solucion[(i+1) % n_ciudades];
			suma += distancias[n1][n2];
		}

		//si es la primera iteración la guardamos
		if(k == 0){
			distancia_min = suma;
			for(int i = 0; i < n_ciudades; i++)
				solucion_final[i] = solucion[i];
		}
		else{
		//si no es la primera iteración comparamos	
			if(suma < distancia_min){
				distancia_min = suma;
				
				for(int i = 0;i < n_ciudades; i++)
					solucion_final[i] = solucion[i];
			}

		}
		//reiniciamos solución y candidatos
		for(int i = 0;i < n_ciudades;i++){
			solucion[i] = -1;
			candidatos[i] = true;
		}
		
		cont = 0;
	}
	
	cout << "DIMENSION: " << n_ciudades << endl;
	/*for(int i = 0; i < n_ciudades; i++)
			cout << solucion_final[i] + 1 << " " << ciudad[solucion_final[i]][0] << " " << ciudad[solucion_final[i]][1] << endl;*/

	//DISTANCIA RECORRIDO
	cout << endl << distancia_min << endl;

	return 0;
}
