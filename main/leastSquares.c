#include <stdio.h>
#include <math.h>

int main(){
	int i, rows;

	printf("How many data points? ");
	scanf("%d", &rows);

	float a, b;
	float x[rows], y[rows], xsq[rows], xy[rows];
	float sum_x, sum_y, sum_xsq, sum_xy;
	sum_x = sum_y = sum_xsq = sum_xy = 0;

	for (i=0; i < rows; i++){
		printf("%d\tx: ", i);
		scanf("%f", &x[i]);	

		printf("\ty: ");
		scanf("%f", &y[i]);	

		xsq[i] = pow(x[i], 2);
		xy[i] = x[i] * y[i];

		sum_x += x[i];
		sum_y += y[i];
		sum_xsq += xsq[i];
		sum_xy += xy[i];
	}

	printf("\n X\t Y\t X2\t XY\n");	
	for (i=0; i < rows; i++)
		printf("%.2f\t%.2f\t%.2f\t%.2f\n", x[i], y[i], xsq[i], xy[i]);

	a = ((rows * sum_xy) - (sum_x * sum_y)) / ((rows * sum_xsq) - pow(sum_x, 2));
	b = ((sum_xsq * sum_y) - (sum_x * sum_xy)) / ((rows * sum_xsq) - pow(sum_x, 2));

	printf("------------------------------\n");
	printf("%.2f\t%.2f\t%.2f\t%.2f\n", sum_x, sum_y, sum_xsq, sum_xy);
	printf("\nA: %.2f\t\tB: %.2f\n", a, b);
	printf("y=%.3fx+%.3f\n", a, b);
}
		
