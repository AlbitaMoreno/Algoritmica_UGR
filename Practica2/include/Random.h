/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Declaración de la clase "MyRandom"
//
// Fichero: Random.h
//
/***************************************************************************/

#ifndef RANDOM
#define RANDOM

/////////////////////////////////////////////////////////////////////////////
// Generador de números aleatorios. 
// Los objetos de esta clase sirven para generar números aleatorios a demanda 
// con el metodo "Next" entre los valores "min" y "max". 

class MyRandom
{
private:
	
	// PRE: minVal <= MaxVal
    int minVal;	// Mínimo Valor
    int maxVal;	// Máximo valor

	/***********************************************************************/
	// Inicializa el generador de números aleatorios 
	// Es un método privado que se invoca solo al actuar el constructor.
	
	void InitMyRandom (void); 
    
public:
	
	/***********************************************************************/	
	// Constructor
	
    MyRandom (int el_minimo, int el_maximo);

	/***********************************************************************/	
	// Calcula y devuelve un número aleatorio en el rango prefijado.
	
    int Next (void);

	/***********************************************************************/
	// Devuelve el menor y mayor valor posible

    int Min (void);
    int Max (void);

	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////

#endif
 
