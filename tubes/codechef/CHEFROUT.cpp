#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    int size;
    string inp;
    bool cooked;
    bool slept;
    char a;
    string ans;
    cin>>testcases;
    while(testcases--) {
        cin>>inp;
        ans="yes";
        for(int i=0;i<inp.length();i++) {
            if( (i+1)<inp.length() && inp[i]=='E' && inp[i+1]=='C')
                ans="no";
            else if((i+1)<inp.length() && inp[i]=='S' && inp[i+1]!='S')
                ans="no";
        }
        cout<<ans<<"\n";
    }

    return 0;
}