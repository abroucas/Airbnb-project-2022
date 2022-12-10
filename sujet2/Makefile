# authors : Jade CANO & Astrid BROUCAS ING 1 GM 1
# date : 30/11/2022
# OS : Linux

CC = gcc # compilateur
CFLAGS = -g -wall -fsanitize = adress # contient toutes les infos de compilation
# library flags 
LIBFLAGS = -lm
RM = rm -f

SRC = $(wildcard *.c) # fichiers sources
OBJ = $(SRC : %.c=%.o) # fichiers objets
EXEC = exec

all : $(EXEC) # exécute tout ce qui est exécutable

$(EXEC) : $(OBJ)                 # l'exécutable prend tout les fichiers .o
	$(CC) $^ -o $@ $(LIBFLAGS)   

%.o : %.c                        # transforme les fichiers .c en fichiers .o
	$(CC) -c $< -o $@



.PHONY : clean


clean:
	rm -rf $(OBJ)  $(EXEC)

run :
	if [-x $(EXEC)]; then\
		./$(EXEC);\

	fi