#include <stdio.h>

int main() {
	int n;

	float f, k;
	int j = 1;
	float f1 = 1, f2 = 0;
	float x[100];
	float y[100];
	float p[100];

	printf("No. of data points: ");
	scanf("%d", &n);

	if (n <= 1) {
		printf("Atleast 2 data points are required\n");
		return -1;
	}


	printf("This will form a %d order newton's polynomial\n", n - 1);
	
	printf("Enter the values for x:\n ");
	for (int i = 0; i < n; i++) {
		printf("> ");
		scanf("%f", &x[i]);
	}

	printf("Enter the values for y:\n ");
	for (int i = 0; i < n; i++) {
		printf("> ");
		scanf("%f", &y[i]);
	}

	printf("For what value of x to interpolate f(x) at? ");
	scanf("%f", &k);

	f = y[0];

	do {
		for (int i = 0; i < n - 1; i++) {
			p[i] = (y[i+1] - y[i]) / (x[i+j] - x[i]);
			y[i] = p[i];
		}

		f1 = 1;
		for (int i = 0; i < j; i++) {
			f1 *= (k - x[i]);
		}

		f2 += (y[0] * f1);

		n--;
		j++;

	} while (n != 1);


	f += f2;
	printf("\nf(%f) = %f", k, f);
}
