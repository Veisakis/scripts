#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1)
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL){
				printf("cat: Cannot open %s\n", *argv);
				return 1;
			}
			else {
				filecopy(fp, stdout);
				fclose(fp);
			}
	return 0;
}

int main_v2(int argc, char *argv[]){
	FILE *fp;
	void filecopy(FILE *, FILE *);
	char *prog = argv[0];

	if (argc == 1)
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL){
				fprintf(stderr, "%s: Cannot open %s\n", prog, argv);
				exit(1);
			}
			else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		
	if (ferror(stdout)){
		fprintf(stderr, "%s: error during writing to stdout\n", prog);
		exit(2);
	}
	exit(0);
}

void filecopy(FILE *ifp, FILE *ofp){
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
