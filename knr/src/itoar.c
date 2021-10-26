void itoar(int n, char s[]){
	static int i = 0;

	if (n / 10)
		itoar(n/10, s);

	s[i++] = n % 10 + '0';
}

