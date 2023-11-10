CC=gcc
CFLAGS=-I.
DEPS=testfuncex.h
PROJECT=testmain
OBJ=testmain.o testfunc.o

%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROJECT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(PROJECT)
	rm *.o
