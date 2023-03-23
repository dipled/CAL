CC = gcc #your compiler here
FLAGS = -c -Wall #your flags here
LIBS = -lm #all your libs here
all: sorts #all your labels here

clean:
	rm  *.out *.o
sorts: sortsC
	${CC} sorts.o ${LIBS} -o sorts.out

sortsC:
	${CC} ${FLAGS} sorts.c 
