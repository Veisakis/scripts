#include <stdio.h>
#include <math.h>

void vectors(float pf, float s, float *p, float *q){
	*p = s * pf;	
	*q = sqrt(pow(s,2) - pow(*p,2));
}

void main(){
	float PF, S, P, Q;

	printf("PF: ");
	scanf("%f", &PF);

	printf("S [kVA]: ");
	scanf("%f", &S);

	vectors(PF, S, &P, &Q);

	printf("\nApparent Power: %.2f kVA\n", S);
	printf("Real Power: %.2f kW\n", P);
	printf("Reactive Power: %.2f kVAr\n", Q);
}
