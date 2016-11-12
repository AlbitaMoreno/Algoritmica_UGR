/***************************************************************************/
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// 
//
// Minimizando el número de visitas al proveedor
// Fichero : TSM2.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;

/******************************************************************************/
/*****************************************************************************/

double DistanciaVector(int V[],int tamanio, double **distancia);
void Insertar(int v[], int elemento, int pos, int tamanio);
void CopiarVector(const int origen[], int destino[], int tamanio);

/******************************************************************************/
/*****************************************************************************/
//MAIN

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
	bool usados[n_ciudades];				// Vector de booleanos de ciudades ya usadas en el circuito(estará a 0 si no se ha insertado todavia)
	int v[n_ciudades];



	for(int i = 0; i < n_ciudades; i++){
		fentrada >> comentario;
		fentrada >>ciudad[i][0];			// Almeceno la coordenada x en la primera columna
		fentrada >>ciudad[i][1];			// y la coordenada y en la segunda.
		
		usados[i]=0;		//Inicializo todo el vector a no usados.
	}

	fentrada.close();

	//ya tengo mi matriz con dos columnas, las coordenadas de las ciudades
	int este,oeste,norte;
	oeste = este = norte = 0;

	for(int i = 0; i < n_ciudades; i++){
	//lo que primero voy a hacer es la ciudad que hay más al oeste, el menor valor de X que hay

		if(ciudad[i][0] < ciudad[oeste][0])
				oeste = i;
			

		if(ciudad[i][0] > ciudad[este][0])
				este = i;
			

		if(ciudad[i][1] > ciudad[norte][1])
				norte = i;
	}


	usados[oeste] = 1;			// Marco que están siendo usados puesto que forman parte del triangulo inicial.
	usados[este] = 1;
	usados[norte] = 1;

	double **distancia;							//Matriz de distancias.
	distancia = new double*[n_ciudades];
	
	for(int i=0; i<n_ciudades;i++){
		distancia[i]=new double[n_ciudades];
	}

		
	//Calculo de distancias
	for(int i=0; i < n_ciudades; i++){
		for(int j=0; j<n_ciudades; j++){
			distancia[i][j]= sqrt(pow((ciudad[j][0]-ciudad[i][0]),2)+pow((ciudad[j][1]-ciudad[i][1]),2));
		}
	}

	v[0]=oeste;
	v[1]=norte;
	v[2]=este;
	
	int dist_min = 999999,aniadir;
	
	int v_aux[n_ciudades];
	int v_inicial[n_ciudades];
	
	CopiarVector(v, v_inicial, 3);

	for(int h = 3; h < n_ciudades; h++){

		for(int j = 0; j < n_ciudades; j++){

			for(int i = 1; i < (h+1); i++){

				if(!usados[j]){					//En primer lugar comprobamos que la ciudad a probar no esté ya en el circuíto.
					CopiarVector(v_inicial, v_aux, h);
					Insertar(v_aux, j, i, h);

					if(dist_min > DistanciaVector(v_aux, h+1, distancia)){
						dist_min = DistanciaVector(v_aux, h+1, distancia);
						CopiarVector(v_aux, v, h+1);
						aniadir = j;
					}

				}
		
			}
		
		}
		
		CopiarVector(v, v_inicial, h+1);
		usados[aniadir]=1;
		dist_min = 999999;
	}
	
	/*for(int i = 0; i < n_ciudades; i++)
		cout << " " << v[i] << " " << ciudad[v[i]][0] << " " << ciudad[v[i]][1] << endl;
*/
	cout << " " << DistanciaVector(v, n_ciudades, distancia);
	cout << endl << endl;
}

/******************************************************************************/
/*****************************************************************************/
/****************************************************************************/
/***************************************************************************/
//FUNCIONES

double DistanciaVector(int V[],int tamanio, double **distancia){			
// Devuelve la distancias del circuito entre las ciudades pasadas en el vector V (si V={1,2,3} devuelve la distancia total del triángulo 1,2,3,1)
	double total = 0;
	total = distancia[ V[0] ][ V[tamanio-1] ];
	for(int i=0; i < tamanio-1 ; i++){
		total += distancia[V[i]][V[i+1]];
	}
	return total;
}

/******************************************************************************/
/*****************************************************************************/

void Insertar(int v[], int elemento, int pos, int tamanio){					// El vector tendra que tener un espacio al final para que no se pierda el ultimo valor.
	for(int i = tamanio; i >=pos; i--){
		v[i]=v[i-1];
		if(i==pos)
			v[i]=elemento;
		
	}
}

/******************************************************************************/
/*****************************************************************************/

void CopiarVector(const int origen[], int destino[], int tamanio){			// Copia la el vector origen en el vector destino.

	for(int i = 0; i< tamanio; i++){
		destino[i] = origen[i];
	}
}


