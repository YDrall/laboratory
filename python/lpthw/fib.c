#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
	if( n==0 || n ==1)
		return 1;
	else
		return fib(n-1) +fib(n-2);
}


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "usage: %s range\n", argv[0]);
		exit(0);
	}

	printf("Result is: %d\n", fib(atoi(argv[1])) );
	return 0;

}

