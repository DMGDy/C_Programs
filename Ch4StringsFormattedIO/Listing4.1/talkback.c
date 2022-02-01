#include <stdio.h>
#include <string.h>

#define DENSITY 62.4
int main(void)	{
	float weight, volume;
	int size, letters;
	char name[40];

	fprintf(stdout,"Hi! What's your first name?\n");
	fscanf(stdin,"%s",name);
	fprintf(stdout,"%s, What is your weight in pounds?\n", name);
	fscanf(stdin,"%f",&weight);

	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;

	fprintf(stdout,"Well, %s, your volume is %2.2f cubic feet. \n",
			name, volume);
	fprintf(stdout,"Also your first name has %d letters,\n", letters);
	fprintf(stdout,"and we have %d bytes to store it.\n", size);

	return 0;
}
