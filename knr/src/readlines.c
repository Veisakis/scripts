#define MAXLINES 5000
#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines, char *s){
	int len, nlines;
	char *p, line[MAXLEN]
	
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= MAXLINES)
			return -1;
		else {
			line[len-1] = '\0';
			
			strcpy(s, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}	
