int strend(char *s, char *t){
	while (*s++);

	for (int i=0; *t++; i++);
	for (; *--t == *--s; i--);

	if (i == -1)
		return 1;
	
	return 0;
}
