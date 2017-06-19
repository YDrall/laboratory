#include <stdio.h>

#define DIR_UP_RIGHT 0
#define DIR_UP_DOWN 1
#define DIR_DOWN_RIGHT 2
#define DIR_DOWN_UP 3

int main() {
    int tests;
    int n,i,j,k,dual_start,no_ans,spot_count_copy;
    int spot_count;
    int dir;
    char plate[2][500];
    scanf("%d",&tests);
    while(tests--) {
        scanf("%d",&n);
        spot_count =0;
        dual_start =0;
        no_ans=1;
        for(i=0;i<2;i++) {
            for(j=0;j<n;j++) {
                scanf(" %c",&plate[i][j]);
                if(plate[i][j]=='#')
                    spot_count +=1;
            }
        }

        // for(i=0;i<2;i++) {
        //     for(j=0;j<n;j++) {
        //             printf("%c",plate[i][j]);
        //     }
        //     printf("\n");
        //     printf("spot_count = %d\n",spot_count);
        // }

        for(i=0;i<n;i++) {
            if(plate[0][i]=='#' && plate[1][i]=='#') {
                dual_start=2;
                spot_count -=1;
                break;
            }
            if(plate[0][i]=='#') {
                dir = DIR_UP_RIGHT;
                spot_count-=1;
                dual_start=4;
                break;
            }
            else if(plate[1][i]=='#') {
                dir = DIR_DOWN_UP;
                spot_count-=1;
                dual_start=4;
                break;
            }
        }
        spot_count_copy=spot_count;
        while(spot_count!=0 && dual_start>0) {
            if(dual_start==2) {
                dir=DIR_UP_RIGHT;
                dual_start--;
            }
            else if(dual_start==1) {
                dir = DIR_DOWN_RIGHT;
                dual_start--;
            }
            else dual_start=0;
            spot_count=spot_count_copy;
            k=i;
            // printf("sport count is %d",spot_count);
            while(k<n) {
                if(dir == DIR_UP_RIGHT && plate[1][k]=='#') {
                        dir = DIR_DOWN_UP;
                        spot_count-=1;
                        // printf("condition 1\n");
                }
                else if(dir == DIR_UP_RIGHT && plate[0][k+1]=='#') {
                    dir = DIR_UP_RIGHT;
                    k++;
                    spot_count -=1;
                    // printf("condition 2\n");
                }
                else if(dir==DIR_UP_DOWN && plate[0][k+1]=='#') {
                    dir = DIR_UP_RIGHT;
                    k++;
                    spot_count -=1;
                    // printf("condition 3\n");
                }
                else if(dir == DIR_DOWN_UP && plate[1][k+1]=='#') {
                    dir = DIR_DOWN_RIGHT;
                    k++;
                    spot_count -=1;
                    // printf("condition 4\n");
                }
                else if(dir==DIR_DOWN_RIGHT && plate[0][k]=='#') {
                    dir = DIR_UP_DOWN;
                    spot_count -=1;
                    // printf("condition 5\n");
                }
                else if(dir==DIR_DOWN_RIGHT && plate[1][k+1]=='#') {
                    dir = DIR_DOWN_RIGHT;
                    k++;
                    spot_count -=1;
                    // printf("condition 6\n");
                }
                else {
                    // printf("condition break\n");
                    break;
                }
            }
        }
    // printf("final spot count si %d\n",spot_count);
        if(spot_count==0) 
            printf("yes\n");
        else 
            printf("no\n");
    }
    return 0;
}