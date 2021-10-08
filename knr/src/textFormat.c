void getLine(){
	int c;
	int i = 0;

	while ((c = getchar()) != EOF){	
		
		if (c == '\n'){
			putchar(c);
			i = 0;
		}
		
		if (i >= MAXLINE){
			if (c == '\n')
				putchar(c);
			else{
				printf("\n");
				i = 0;
			}
		}

		if (i < MAXLINE){
			putchar(c);
			++i;
		}

	}
}

