#include <stdio.h>

unsigned long long int power(int n, int exp);

int main(void)	{
	signed int number, exponent;

	fprintf(stdout,"Enter base and exponent:\n");
	while (fscanf(stdin,"%d %d", &number, &exponent))	{
		fprintf(stdout,"%d^%d  %lld \n",number,exponent, power(number,exponent));
		fprintf(stdout,"enter a value: \n");

	}
	return 0;
}


unsigned long long int power(int number, int exponent)	{
	unsigned long long res;

	if (exponent > 0)	{
		res = number * power(number, exponent - 1);
		}
	else	{
		res = 1;
	}
	return res;
}
