#include<stdio.h>

int main() {
	int tests;
	int n,m;
	int i;
	int u,v;
	scanf("%d",&tests);
	while(tests--) {
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++) {
			scanf("%d %d",&u,&v);
		}
		if(n%2==0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}