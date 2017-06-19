#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[100000];
long long int hash[26]; 

int compare(const void *p,const void *q)
{
	long long int x = *(const long long int *)p;
    long int long y = *(const long long int *)q;
	if(x<y)
		return 1;
	else if(x>y)
		return -1;
	return 0;
}

long long int getmin(long long int *a,int size)
{
	long long int i=0;
	for(i=size-1;i>=0;i--)
	{
		if(a[i]!=0)
			return a[i];
	}
	return a[i];
}

long long int inKGood(char *a,long long int k)
{
	long long int i=0;
	long long int max,min;
	long long int count=0;
	while(a[i]!='\0')
	{
		hash[((a[i])-'a')%26]+=1;
		i++;
	}
	qsort(hash,26,sizeof(long long int),compare);
	min = getmin(hash,26);

	for(i=0;i<26;i++)
	{
		if(hash[i]-min<k)
		{
			break;
		}
		count += (hash[i]-k -min);
	}

	return count;
}

int main()
{
	int testcases;
	long long int KWord;

	scanf("%d",&testcases);
	while(testcases--)
	{
		scanf("%s",word);
		scanf("%lli",&KWord);
		memset(&hash,0,sizeof(hash));
		printf("%lli\n",inKGood(word,KWord));
	}
	
	return 0;
}