#ifndef SORT_H
#define SORT_H

int getLine(char *line);
int numcmp(char *s1, char *s2);
int strcomp(char *s1, char *s2);
int readlines(char *lineptr[], int maxlines); 

void strtolower(char *s);
void writelines(char *lineptr[], int nlines);
void reverseLines(char *lineptr[], int size);
void qsort(char *lineptr[], int left, int right, int (*comp)(void *, void *));

#endif

