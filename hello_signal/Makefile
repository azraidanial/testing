CC=gcc
CFLAGS=-I.
# DEPS=<list_of_header_files>
PROJECT=hello_sigaction
OBJ=hello_sigaction.o

%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROJECT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(PROJECT)
	rm *.o
