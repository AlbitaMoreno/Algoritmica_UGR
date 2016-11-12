/***************************************************************************/
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// 
//
// Fichero : TSM3.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

	void LeerDatos(){}

int main(int argc, char *argv[]){

	if(argc < 2){
		cout <<"Falta fichero de entrada\n";
		return -1;
	}

	string comentario;
	ifstream fentrada;
	
	int n_ciudades;
	
	fentrada.open(argv[1]);
	fentrada >> comentario;
	fentrada >> n_ciudades;
	
	double ciudad[n_ciudades][2];
	
	for(int i=0; i<n_ciudades; i++){
		fentrada >> comentario;
		fentrada >> ciudad[i][0];
		fentrada >> ciudad[i][1];
	}


	fentrada.close();


	double distancias[n_ciudades][n_ciudades];
	
	for(int i = 0; i < n_ciudades; i++)
		for(int j = 0; j < n_ciudades; j++)
			distancias[i][j] = sqrt(pow(ciudad[i][0]-ciudad[j][0],2)+pow(ciudad[i][1]-ciudad[j][1],2));

	int solucion[n_ciudades];
	bool candidatos[n_ciudades];
	
	//Inicializamos el vector solucion a -1
	//Ponemos todos los candidatos a true (disponibles)
	for(int i = 0;i < n_ciudades;i++){
		solucion[i] = -1;
		candidatos[i] = true;
	}
	
	int cont = 0;
	
	bool vacio = true;

	int solucion_final[n_ciudades];
	int distancia_min;

	for(int k = 0; k < n_ciudades; k++){

		//Realizamos el algoritmo empezando por todas las ciudades
		//Metemos la primera ciudad en solucion y la quitamos de candidatos
		solucion[cont] = k;
		candidatos[k] = false;
		cont++;

		for(int i = 0 ; i < n_ciudades;i++)
			if(candidatos[i] == true)
				vacio = false;


		//Mientras queden ciudades en candidatos
		while(!vacio){
		
			//si solo tenemos 1 ciudad
			if(solucion[1] == -1){
				bool encontrado = false;
				
				//cogemos la distancia minima la de la primera ciudad
				double dist_min=distancias[k][0];
				int min = 0;
				
				//mientras que la ciudad no este disponible en candidatos y no sea ella misma seguimos buscando
				while(!encontrado){
					if(candidatos[min] && dist_min != 0)
						encontrado = true;
					
					else{
						min++;
						dist_min=distancias[k][min];
					}
				}
				
				//Ahora que tenemos una distancia disponible buscamos la mínima
				for(int i = min + 1; i < n_ciudades; i++)
					if(distancias[k][i] < dist_min && candidatos[i] && distancias[k][i] != 0){
						min = i;
						dist_min = distancias[k][i];
					}
				//Metemos la ciudad mínima en solución y la quitamos de candidatos
				candidatos[min] = false;
				solucion[cont] = min;
				cont++;

			}
			
			else{
				bool encontrado = false;
				int extremo1 = solucion[0],extremo2 = solucion[cont-1];
				double dist_min1 = distancias[extremo1][0];
				int min1 = 0;
				//calculamos la distancia disponible del extremo1
				while(!encontrado){
					if(candidatos[min1] && dist_min1 != 0)
						encontrado = true;
						
					else{
						min1++;
						dist_min1=distancias[extremo1][min1];
					}
				}
				
				//calculamos la distancia mínima del extremo1
				for(int i = min1 + 1; i < n_ciudades; i++)
					if(distancias[extremo1][i] < dist_min1 && candidatos[i] && distancias[extremo1][i] != 0){
						min1 = i;
						dist_min1 = distancias[extremo1][i];
					}
					
				encontrado = false;
				
				double dist_min2 = distancias[extremo2][0];
				int min2 = 0;
				
				//calculamos la distancia disponible del extremo2
				while(!encontrado){
					if(candidatos[min2] && dist_min2 != 0)
						encontrado=true;
						
					else{
						min2++;
						dist_min2=distancias[extremo2][min2];
					}
				}
				
				//calculamos la distancia mínima del extremo2
				for(int i = min2 + 1; i < n_ciudades; i++)
					if(distancias[extremo2][i] < dist_min2 && candidatos[i] && distancias[extremo2][i] != 0){
						min2 = i;
						dist_min2=distancias[extremo2][i];
					}
					
				//comparamos y nos quedamos con la menor
				if(dist_min1 < dist_min2){
					for(int i = cont; i > 0; i--)
						solucion[i] = solucion[i-1];
			
					candidatos[min1] = false;
					solucion[0] = min1;
					cont++;
				}
				
				else{
					candidatos[min2] = false;
					solucion[cont] = min2;
					cont++;
				}

			}
			
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
			for(int i = 0;i < n_ciudades; i++)
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

		//reiniciamos solución y los candidatos
		for(int i = 0;i < n_ciudades; i++){
			solucion[i] = -1;
			candidatos[i] = true;
		}
		
		cont = 0;
	}
	
	cout << "DIMENSION: " << n_ciudades << endl;
	/*for(int i=0;i<n_ciudades;i++)
		cout << solucion_final[i] + 1 << " " << ciudad[solucion_final[i]][0] << " " << ciudad[solucion_final[i]][1] << endl;

	//DISTANCIA RECORRIDO*/
	cout<<endl<<distancia_min<<endl;

	return 0;
}
