#include <stdio.h>

int move_disc(int n,int begin, int end);

int main(void)	{
	int n_disc, begin_peg, end_peg;

	fprintf(stdout,"Enter disc number, beginning peg, and ending peg\n");
	fscanf(stdin,"%d %d %d",&n_disc, &begin_peg, &end_peg);
	move_disc(n_disc,begin_peg,end_peg);
	return 0;
}

int move_disc(int n,int begin, int end)	{
	int aux;
	aux = 6 - (begin + end);
	if(n==1)	{
		fprintf(stdout,"move disc %d from peg %d to peg %d\n",n,begin,end);
	}
	else	{
		move_disc(n-1,begin,aux);
		fprintf(stdout,"move disc %d from %d to %d\n",n,begin,end);
		move_disc(n-1,aux,end);
	}
	return 0;
}
