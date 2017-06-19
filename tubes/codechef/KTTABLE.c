#include <stdio.h>

int main()
{
	int testcases;
	int num_students;
	scanf("%d",&testcases);
	int i=0,j=0,k=0;
	int count=0;
	while(testcases--)
	{
		scanf("%d",&num_students);
		int A[num_students+1];
		A[0]=0;
		count = 0;
		for(i=1;i<=num_students;i++)
		{
			scanf("%d",&A[i]);
		}
		for(i=1;i<=num_students;i++)
		{
			scanf("%d",&j);
			if(j<=A[i]-A[i-1])
				count++;
		}
		printf("%d\n", count);
	}
}