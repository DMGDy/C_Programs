#include <stdio.h>

int one_three(void);
int two(void);

int main(void)	{
	fprintf(stdout,"starting now:\n");
	one_three();
	fprintf(stdout,"done!");

	return 0;
}

int one_three(void)	{
	fprintf(stdout,"one\n");
	two();
	fprintf(stdout,"three\n");

	return 0;
}

int two(void)	{
	fprintf(stdout,"two\n");

	return 0;
}
