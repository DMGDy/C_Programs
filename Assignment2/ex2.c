#include <stdio.h>

int convert(int age);

int main(void)	{
	int age;
	fprintf(stdout,"Enter your age: ");
	fscanf(stdin,"%d", &age);
	fprintf(stdout,"your age is %d", age);
}
