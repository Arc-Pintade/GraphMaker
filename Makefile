CC = g++
SFML = -lsfml-graphics -lsfml-window -lsfml-system 
SRC=$(shell ls ./src/*.cpp)
OBJ=$(SRC:.cpp=.o)
.PHONY: clean
.PHONY: clean-all
all: graphMaker
clean:
	rm -f ./src/*.o
clean-all:
	rm -f ./src/*.o graphMaker
%.o: %.cpp
	$(CC) -c $(SFML) -o $@ $<
graphMaker: $(OBJ) 
	$(CC) $^ $(SFML) -o $@ 
