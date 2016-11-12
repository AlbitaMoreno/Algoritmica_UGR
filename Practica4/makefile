#
#
#	
######################################################################


BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all : inicio mr-proper $(BIN)/maze $(BIN)/TSP_bb $(BIN)/maze2 fin

inicio : 
	@echo ------------------------------------------------------------
	@echo Grado en Ingenieria Informatica - Grupo B3
	@echo
	@echo ------------------------------------------------------------

fin : 
	@echo Se han realizado las operaciones con exito

#########################################################################
# Objetos
#
#########################################################################

$(OBJ)/Random.o : $(SRC)/Random.cpp $(INCLUDE)/Random.h
	g++ -c -o $@ $(SRC)/Random.cpp -I$(INCLUDE)

$(OBJ)/maze.o : $(SRC)/maze.cpp $(INCLUDE)/Random.h
	g++ -c -o $@ $(SRC)/maze.cpp -I$(INCLUDE)	-std=gnu++0x

$(OBJ)/maze2.o : $(SRC)/maze2.cpp $(INCLUDE)/Random.h
	g++ -c -o $@ $(SRC)/maze2.cpp -I$(INCLUDE)	-std=gnu++0x
	
#########################################################################
# Ejecutables
#
#########################################################################

$(BIN)/maze2 : $(OBJ)/maze2.o $(OBJ)/Random.o
	g++ -o $@ $^	-std=gnu++0x

$(BIN)/maze : $(OBJ)/maze.o $(OBJ)/Random.o
	g++ -o $@ $^	-std=gnu++0x

$(BIN)/TSP_bb : $(SRC)/TSP_bb.cpp
	g++ -o $@ $^	
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
