#include <stdio.h>
#define MAXVAL 100

int sp = 0;
double copiedVal;
double tempVal;
double val[MAXVAL];

void push(double f){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error push(): Stack overflow!");
}

double pop(void){
	if (sp > 0)
		return val[--sp];
	else{
		printf("Error pop(): Empty stack!");
		return 0.0;
	}
}

void peek(void){
	if (sp > 0)
		printf("%g\n", val[sp]);
	else
		printf("Error peek(): Empty stack!");
}

void copy(void){
	if (sp > 0)
		copiedVal = val[sp];	
	else
		printf("Nothing to copy...");
}

void flip(void){
	if (sp > 1){
		tempVal = val[1];
		val[1] = val[0];
		val[0] = tempVal;
	}	 	
	else
		printf("Error flip(): There are not at least 2 elements in the stack");
}

void clean(void){
	while (sp > 0)
		val[--sp] = ' ';	
}
