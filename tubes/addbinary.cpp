#include <bits/stdc++.h>

using namespace std;

string addBinary(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string *larger = A.length()>=B.length()?&A:&B;
    string *smaller = A.length()<B.length()?&A:&B;
    string result="";
    int carry=0;
    int sum;
    int j;
    int diff=(*larger).length()-(*smaller).length();
    for(int i=(*smaller).length(),j=(*larger).length();i>0;i--,j--) {
        sum = atoi((*smaller)[i].c_str())+atoi((*larger)[j].c_str())+carry;
        if(sum>1) {
            carry=1;
            sum=0;
        }
        else {
            carry = 0;
        }
        if(sum==1)
            result = "1"+result;
        if(sum==0)
            result = "0"+result;
    }
    if(carry==1)
        result = "1"+result;
    return result;
}


int main() {
    string a = "100";
    string b = "11";
    cout<<addBinary(a,b)<<endl;
}