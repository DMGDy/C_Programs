#include <stdio.h>
#include <string.h>

int main(void)	{
	char b[10];
	int size;
	fscanf(stdin,"%s",b);
	fprintf(stdout,"%s\n",b);
	fprintf(stdout,"length of b = %zd\n",strlen(b));
	size = sizeof b;
	fprintf(stdout,"%d\n",size);

	return 0;
}
