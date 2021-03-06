#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <chrono>
#include "Random.h"

using namespace std::chrono;

// generador de ejemplos para el problema del elemento en su posición. 
//Para rellenar el vector de tamaño n, genera todos los enteros entre -(n-1) y (n-1) en un vector auxiliar; 
//después obtiene una permutación aleatoria de ese vector, se queda con los n primeros elementos, 
//y los ordena de forma creciente

double uniforme();
void Ordena(int *vec, int n);
bool busqueda(int *vec, int i, int n);

/************************************************************************************/
/************************************************************************************/

int main(int argc, char * argv[]){
    
    high_resolution_clock::time_point tantes, tdespues;
    duration<double> transcurrido;

    srandom(time(0));

    if (argc != 2){
        cerr << "Formato " << argv[0] << " <num_elem>" << endl;
        exit(1);
    }

    int n = atoi(argv[1]);  //num_elementos
    int m = 2*n - 1;

    int * T = new int[n];
    assert(T);  //verifica que T es distinto de 0, no está vacío
    int * aux = new int[m];
    assert(aux);

    srand(time(0));
    //genero todos los enteros entre -(n-1) y n-1

    for (int j = 0; j < m; j++)
        aux[j] = j - (n - 1);

    //algoritmo de random shuffling the Knuth (permutación aleatoria) 
    for (int j = m -1; j > 0; j--) {
        double u = uniforme();
        int k = (int)(j*u);
        int tmp = aux[j];
        aux[j] = aux[k];
        aux[k] = tmp;
    }

    for (int j=0; j<n; j++) 
        T[j]=aux[j];

    int clave = 0;
    Ordena(T,n);
    
    tantes = high_resolution_clock::now();

    bool res = busqueda(T,clave,n);

    tdespues = high_resolution_clock::now();    
    transcurrido = duration_cast<duration<double>>(tdespues - tantes);
    cout << n << " " << transcurrido.count() << endl;

    /**************************************************************************/
    /*************************************************************************
    //PARA APLICAR EL ALGORITMO DV CON REPETIDOS
    
    MyRandom generador(0,n);

    for(int i = 0; i < n; i++){
        T[i] = generador.Next();
    }

    Ordena(T,n);

    tantes = high_resolution_clock::now();

    int j = EnSuPosicionFBruta(T,n);
    
    tdespues = high_resolution_clock::now();    
    transcurrido = duration_cast<duration<double>>(tdespues - tantes);
    cout << n << " " << transcurrido.count() << endl;

   cout << endl;*/

    delete [] aux;
}

double uniforme(){ //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C. 
    int t = rand();
    double f = ((double)RAND_MAX+1.0);
    return (double)t/f;
}

void Ordena(int *vec, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(vec[i] > vec[j]){
                int tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
            }
        }
    }
}

bool busqueda(int *v,int i, int n){
    bool res;

    if(i <= n){
        if(v[i] == i)
            res = true;
        else{
            i++;
            int m = ((n - i)/2) + i;
            if(i < v[m]) 
                res = busqueda(v, i, m-1);
            else if(i > v[m]) 
                res = busqueda(v, m+1,n);
            else res = true;
        }     
    }
    else 
        res = false;
    return(res);
}