#include<stdio.h>

int main()
{
int testcases=0,segements,iterator,max,max_pos,temp;
scanf("%d",&testcases);
while(testcases--)
	{
	max=0,temp=0;
	scanf("%d",&segements);

	for(iterator=0;iterator<segements;iterator++)
		{
			scanf("%d",&temp);
            if(max<(temp+iterator))
				{
					max=temp+iterator;
				}

		}
		printf("%d\n",max);

	}
	return 0;
}
