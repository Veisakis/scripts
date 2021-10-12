#ifndef LINE_H
#define LINE_H 

#define MAXLINE 1000
#define NUMBER 1
#define VARIABLE 2

int getLine(char line[]);
void reverse(char s[]);
int getch(void);
void ungetch(int c);
void push(double f);
double pop(void);
double atof(char s[]);
int getop (char s[]);

#endif
