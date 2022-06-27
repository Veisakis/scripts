#ifndef LINE_H
#define LINE_H 

#define MAXLINE 1000

void pstrcat(char *s, char *t);
void reverse(char s[]);
void ungetch(int c);

int getLine(char line[]);
int getch(void);

#endif
