#Makefile to compile the myls.c file into an exe with the name myls.
#Written By Samer Madieh

myls: myls.c
	gcc -o myls myls.c -std=c99