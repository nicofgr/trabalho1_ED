
CC=gcc
CFLAGS=-g -Wall

pilhaEstatica.o: pilhaEstatica.h pilhaEstatica.c
	$(CC) $(CFLAGS) -c pilhaEstatica.c

pilhaDinamica.o: pilhaDinamica.h pilhaDinamica.c
	$(CC) $(CFLAGS) -c pilhaDinamica.c

filaEstatica.o: filaEstatica.h filaEstatica.c
	$(CC) $(CFLAGS) -c filaEstatica.c

filaDinamica.o: filaDinamica.h filaDinamica.c
	$(CC) $(CFLAGS) -c filaDinamica.c

pefe: pilhaEstatica.o filaEstatica.o main.c
	$(CC) $(CFLAGS) -o pefe main.c pilhaEstatica.o filaEstatica.o

pefd: pilhaEstatica.o filaDinamica.o main.c
	$(CC) $(CFLAGS) -o pefd main.c pilhaEstatica.o filaDinamica.o

pdfe: pilhaDinamica.o filaEstatica.o main.c
	$(CC) $(CFLAGS) -o pdfe main.c pilhaDinamica.o filaEstatica.o

pdfd: pilhaDinamica.o filaDinamica.o main.c
	$(CC) $(CFLAGS) -o pdfd main.c pilhaDinamica.o filaDinamica.o 

clean:
	rm *.o pefe pefd pdfe pdfd

