
all:
	gcc -c -fPIC -o emplib.o emplib.c
	gcc -shared -o libemp.so emplib.o

	gcc -L. -o empmain empmain.c -lemp