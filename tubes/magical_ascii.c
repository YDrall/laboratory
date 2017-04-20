#include <stdio.h>
#include <stdlib.h>

char find_nearest(char ch) {
    char TOTAL_MAGIC[12] = {'C','G','I','O','S','Y','a','e','g','k','m','q'};
    char UPPER_MAGICAL[6]= {'C','G','I','O','S','Y'};
    char LOWER_MAGICAL[6] = {'a','e','g','k','m','q'};
    int i;
    int min_dist = 10000;
    int dist;
    for(i=0;i<=12;i++) {
        dist = (int)(TOTAL_MAGIC[i]-ch);
        if(abs(dist)<abs(min_dist)) min_dist = dist;
    }
    return (char)(ch+min_dist);
    // if(ch >='A' && ch <='Z') {
    //     for(i=0;i<7;i++) {
    //         dist = (int)(UPPER_MAGICAL[i]-ch);
    //         if(abs(dist)<abs(min_dist)) min_dist = dist;
    //     }
    //     return (char)(ch+min_dist);
    // }
    // else {
    //     for(i=0;i<7;i++) {
    //         dist = (int)(LOWER_MAGICAL[i]-ch);
    //         if(abs(dist)<abs(min_dist)) min_dist = dist;
    //     }
    //     return (char)(ch+min_dist);
    // }
}

int main()
{
    int testcases;
    int str_len;
    int i;
    scanf("%d",&testcases);
    while(testcases--) {
        scanf("%d",&str_len);
        getchar();
        for(i=0;i<str_len;i++)
            printf("%c",find_nearest(getchar()));
        printf("\n");
    }
    return 0;
}
