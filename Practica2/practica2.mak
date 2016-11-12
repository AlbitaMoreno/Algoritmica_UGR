#makefile para la practica 2 de algoritmica

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all : inicio mr-proper posicion DVposicion fin

inicio : 
	@echo ------------------------------------------------------------
	@echo 
	@echo Algoritmica
	@echo ------------------------------------------------------------

fin : 
	@echo Se han realizado las operaciones con exito


$(OBJ)/Random.o : $(SRC)/Random.cpp $(INCLUDE)/Random.h
	@echo Generando Random.o
	g++ -c -o $@ $(SRC)/Random.cpp -I$(INCLUDE)	-std=c++11

$(OBJ)/posicion.o : $(SRC)/genera-ensuposicion.cpp $(INCLUDE)/Random.h
	g++ -c -o $@ $(SRC)/genera-ensuposicion.cpp -I$(INCLUDE)	-std=gnu++0x

posicion : $(OBJ)/posicion.o $(OBJ)/Random.o
	g++ -o $@ $^

$(OBJ)/DVposicion.o : $(SRC)/DVensupos.cpp $(INCLUDE)/Random.h
	g++ -c -o $@ $(SRC)/DVensupos.cpp -I$(INCLUDE)	-std=gnu++0x

DVposicion : $(OBJ)/DVposicion.o $(OBJ)/Random.o
	g++ -o $@ $^

clean:
	@echo borrando objetos ...
	-rm $(OBJ)/*
	@echo borrados

mr-proper:
	@echo borrando obj y ejecutables ...
	-rm $(OBJ)/* $(BIN)/*
	@echo borrados