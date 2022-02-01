#include <stdio.h>

long double rfact(int n);

int main(void)	{
	int num;

	fprintf(stdout,"Enter a value (q to quit);\n");
	while (fscanf(stdin,"%d",&num) ==1)	{
		if (num < 0)	{
			fprintf(stdout,"no negative numbers\n");
		}
		else	{
			fprintf(stdout,"Factorial through recursion %d!= %Lf\n",num, rfact(num));
		}
		fprintf(stdout,"Enter a value in range(q to quit):\n");
	}
	fprintf(stdout,"finish,\n");

	return 0;
}

long double rfact(int n)	{
	long double factorial;

	if (n > 0) {
		factorial = n * rfact(n-1);
	}
	else	{
		factorial = 1;
	}

	return factorial;
}
