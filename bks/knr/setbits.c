unsigned setbits(unsigned x, int p, int n, unsigned y){
	unsigned mask = ~(~0 << n) << p + 1 - n;
	unsigned reversedMask = ~mask;	
	
	y = y << p + 1 - n;

	x = x & reversedMask;
	y = y & mask;

	return x | y;
}
