CC=gcc
CFLAGS=-I.
DEPS=hellofuncex.h
PROJECT=hello
OBJ=hellomain.o hellofunc.o

%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROJECT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(PROJECT)
	rm *.o

