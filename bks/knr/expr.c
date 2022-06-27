/*Reverse Polish Notation*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER 1

void push(double f);
double pop(void);

int main(int argc, char *argv[]){
	float op2;

	while (--argc > 0) {
		if (isdigit(**++argv))
			push(atof(*argv));

		else
			switch (**argv) {
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: Can't divide by 0\n");
				break;
			default:
				printf("Error: Unknown command %s\n", *argv);
				break;
			}
		}

	printf("\t%.8g\n", pop());
}

#define MAXVAL 100

int sp = 0;
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
