#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    int N;
    int least=0;
    int pairs=0;
    int sum_of_three;
    int abort;
    cin>>testcases;
    while(testcases--) {
        cin>>N;
        int side[N];
        for(int i=0;i<N;i++) {
            cin>>side[i];
        }
        sort(side,side+(sizeof(side)/sizeof(side[0])));
        least = 3;
        pairs = 0;
        // for(int i=0;i<N;i++)
            // cout<<side[i]<<" ";
        // cout<<endl;
        for(int i=2;i<N-1;i++) {
            // cout<<i<<" :i"<<endl;
            // cout<<i<<" :sum_of_three"<<endl;
            if(least==i)
                least+=1;
            abort=0;
            for(int first=0;first<i-1;first++) {
                for(int second=1;second<i;second++) {
                    sum_of_three = side[i] + side[first] + side[second];
                for(int j=least;j<N;j++) {
                    if(sum_of_three>side[j]) {
                        least = j;
                        cout<<"pair found: "<<i<<", "<<first<<", "<<first+1<<". at: "<<least<<". pair count: "<<N-least<<endl;
                        pairs += N-least;
                        abort=1;
                        // cout<<least<<" :least"<<endl;
                        break;
                    }
                    if(abort==1)
                        break;
                }
                if(abort==1)
                    break;
                }
            }
        }
        cout<<pairs<<endl;
    }
    return 0;
}