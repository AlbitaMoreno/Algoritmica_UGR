#
#	MAKEFILE Practica 3
#	
#	Alba Moreno Ontiveros
#	Jesús Mesa González
#	Sergio Díaz Rueda
#	Antonio Javier Rodríguez Pérez
#	
######################################################################

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all : inicio mr-proper $(BIN)/proveedor $(BIN)/TSM1 $(BIN)/TSM2 $(BIN)/TSM3 fin
inicio : 
	@echo ------------------------------------------------------------
	@echo ALGORITMICA
	@echo Grado en Ingenieria Informatica - Grupo B3
	@echo ------------------------------------------------------------

fin : 
	@echo Se han realizado las operaciones con exito

#########################################################################
# VIAJANTE DE COMERCIO, VECINO MÁS CERCANO
#########################################################################

$(BIN)/TSM1 : $(OBJ)/TSM1.o
	@echo VIAJANTE DE COMERCIO, VECINO MÁS CERCANO
	g++ -o $@ $^

$(OBJ)/TSM1.o : $(SRC)/TSM1.cpp
	g++ -c -o $(OBJ)/TSM1.o $(SRC)/TSM1.cpp

#########################################################################
# VIAJANTE DE COMERCIO, CON INSERCIÓN
#########################################################################
	
$(BIN)/TSM2 : $(OBJ)/TSM2.o
	@echo VIAJANTE DE COMERCIO, CON INSERCIÓN 
	g++ -o $@ $^

$(OBJ)/TSM2.o : $(SRC)/TSM2.cpp
	g++ -c -o $(OBJ)/TSM2.o $(SRC)/TSM2.cpp

#########################################################################
# VIAJANTE DE COMERCIO, USANDO NUESTRO ALGORITMO
#########################################################################

$(BIN)/TSM3 : $(OBJ)/TSM3.o
	@echo VIAJANTE DE COMERCIO, USANDO NUESTRO ALGORITMO
	g++ -o $@ $^

$(OBJ)/TSM3.o : $(SRC)/TSM3.cpp
	g++ -c -o $(OBJ)/TSM3.o $(SRC)/TSM3.cpp

#########################################################################
# PROVEEDOR DE FERTILIZANTE
#########################################################################

$(OBJ)/Random.o : $(SRC)/Random.cpp $(INCLUDE)/Random.h
	g++ -c -o $@ $(SRC)/Random.cpp -I$(INCLUDE)
	
$(OBJ)/proveedor.o : $(SRC)/proveedor.cpp $(INCLUDE)/Random.h
	g++ -c -o $@ $(SRC)/proveedor.cpp -I$(INCLUDE)	-std=c++11
	
$(BIN)/proveedor : $(OBJ)/proveedor.o $(OBJ)/Random.o
	@echo PROVEEDOR DE FERTILIZANTE
	g++ -o $@ $^	-std=c++11
	
#########################################################################
# Limpia
#########################################################################
clean:
	@echo borrando objetos ...
	-rm $(OBJ)/*
	@echo borrados

mr-proper:
	@echo borrando obj y ejecutables ...
	-rm $(OBJ)/* $(BIN)/*
	@echo borrados
