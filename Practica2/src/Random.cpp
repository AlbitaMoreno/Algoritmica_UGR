/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Definición de la clase "MyRandom"
//
// Fichero: Random.cpp
//
/***************************************************************************/

#include <cstdlib>
#include <ctime>

#include "Random.h"

using namespace std;


/***********************************************************************/
// Inicializa el generador de números aleatorios 
// Es un método privado que se invoca solo al actuar el constructor.

void MyRandom :: InitMyRandom (void)
{
    time_t t;
    srand ((int) time(&t));     // Inicializa el generador
                                // con el reloj del sistema
}


/***********************************************************************/	
// Constructor

MyRandom :: MyRandom (int el_minimo, int el_maximo) :
    minVal(el_minimo), maxVal(el_maximo)
{
    InitMyRandom();

    int no_lo_uso = Next(); // Desecho el primero
}

/***********************************************************************/	
// Calcula y devuelve un número aleatorio en el rango prefijado.

int MyRandom :: Next (void) {
	
    int rango = (maxVal - minVal)+1;
    int v1 = rango * (rand() / (RAND_MAX*1.0));
    int v2 = minVal + (v1 % rango);

    return (v2);
}

/***********************************************************************/

int MyRandom :: Min (void) 
{
    return (minVal);
}

/***********************************************************************/

int MyRandom :: Max (void) 
{
    return (maxVal);
}

/***********************************************************************/
 
