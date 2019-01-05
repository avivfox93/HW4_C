
CC = gcc
OBJS = main.o City.o Child.o Kindergarten.o General.o
EXEC = prog
COMP_FLAG = -std=c99 -Wall -Werror

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c City.o Child.o Kindergarten.h General.o
	$(CC) -c $(COMP_FLAG) $*.c

City.o: City.c Kindergarten.o

Kindergarten.o: Kindergarten.c Child.o

Child.o: Child.c General.o

General.o: General.c

clean:
	rm -f $(OBJS) $(EXEC)
