#include <stdio.h>

#define max(a,b) a>b? a:b

// long long int max_sub_better(long long int *a,long int size,long long int skip_index)
// {
// 	long long int i=0;
// 	long long int meh=a[0],msf=a[0];

// 	for(i=1;i<size;i++)
// 	{
// 		if(i==skip_index)
// 			continue;
// 		meh= max(a[i],meh+a[i]);
// 		msf = max(meh,msf);
// 	}
// 	return msf;
// }

void swap(void *a, void *b)
{
	void temp= *a;
	*a=*b;
	*b= temp;
}

long long int max_sub_better(long long int *a,long int size,long long int skip_index)
{
	long long int i=0;
	long long int meh=a[0],msf=a[0];
	long long int can_ign=0,can_ign_meh=0;

	for(i=1;i<size;i++)
	{
		if(a[i]<can_ign)
		{
			can_ign = a[i];
			meh += can_ign;
			continue;
		}

		meh= max(a[i],meh+a[i]);
		msf = max(meh,msf);

		can_ign_meh= max(a[i],can_ign_meh+a[i]);

		if(can_ign_meh>mef)
		{
			swap(&can_ign_meh, &meh);
		}
	}

	return msf;
}


int main()
{
	int testcases;
	int numbers =0;
	unsigned long long int  i=0;
	long long int temp=0;
	long long int max;
	scanf("%d",&testcases);
	while(testcases--)
	{
		scanf("%d",&numbers);
		long long int array[numbers];
		for(i=0;i<numbers;i++)
			scanf("%lli",&array[i]);
		max= max_sub_better(array,numbers,-1);
		// for(i=0;i<numbers;i++)
		// {
		// 	if(array[i]<0)
		// 	{
		// 		max = max(max_sub_better(array,numbers,i),max);
		// 	}

		// }
		printf("%lli\n", max);
	}
	
	
	
}