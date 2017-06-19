#include <stdio.h>
#include <algorithm>
char word[100000];
long int hash[26]; 
long int inKGood(char *a,long long int k)
{
	int i=0;
	while(a[i]!='\0')
	{
		hash[(tolower(a[i])-'a')%26]
		i++;
	}
	
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
		printf("%s %lu\n", word, sizeof(word));;
		printf("%li",inKGood(word,KWord);
	}
	
	return 0;
}