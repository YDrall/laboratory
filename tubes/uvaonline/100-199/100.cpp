#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

using namespace std;

int main() {
    int map[MAX_SIZE];
    int from,to,max=0;
    // map = (int*)malloc(sizeof(int)*MAX_SIZE);
    memset(&map,0,MAX_SIZE);

    map[1] = 1;
    for(int i=2;i<MAX_SIZE;i++) {
        int temp=i;
        int counter = 1;
        while(temp>1) {
            if(temp<MAX_SIZE && map[temp]>0) {
                counter += map[temp]-1;
                break;
            }

            if(temp%2==0)
                temp = temp/2;
            else 
                temp = 3*temp +1;
            counter +=1;
        }
        map[i] = counter;
    }

    while(cin>>from>>to) {
        cout<<from<<" "<<to<<" ";
        max =0;
        if(from>to) {
            from = from ^to;
            to = from ^to;
            from = from ^to;
        }

        for(int i=from;i<=to;i++) {
            if(map[i]>max) max = map[i];
        }

        cout<<max<<"\n";
    }

    return 0;
}