#include <stdio.h>

int main()
{
    int num,q;
    int qtype;
    int i;
    int X;
    int L,R;
    scanf("%d %d",&num,&q);
    int value[num];
    for(i=0;i<num;i++) {
        scanf("%d",&value[i]);
        // fprintf(stderr,"%d ",value[i]);
    }
    for(i=0;i<q;i++) {
        scanf("%d",&qtype);
        if(qtype==1) {
            scanf("%d",&X);
            // fprintf(stderr,"%d ",X);
            value[X-1] = !value[X-1];
        }
        else if(qtype==0) {
            scanf("%d %d",&L,&R);
            if(value[R-1]==0) printf("EVEN\n");
            else if(value[R-1]==1) printf("ODD\n");
        }
    }
    return 0;
}
