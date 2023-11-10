all:
	gcc -c -fPIC -o emplib.o emplib.c
	gcc -c -o empmain.o empmain.c
	gcc -shared -o libemplib.so emplib.o
	gcc -L. -o employee empmain.o -l emplib
