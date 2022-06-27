void pstrcat(char *s, char *t){
	for (; *s != '\0'; s++);
	for (; (*s = *t) != '\0'; s++,t++);
}
