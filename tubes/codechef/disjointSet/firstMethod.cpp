#include<iostream>
using namespace std;
void initialize(int *arr,int sz)
{
    for(int i=0;i<sz;i++)
    {
        arr[i]=i;
    }
}

void makeunion(int *arr,int sz,int A,int B)
{
    int temp=arr[A];
    for(int i=0;i<sz;i++)
    {
        if(arr[i]==temp)
            arr[i]=arr[B];
    }
}

bool find(int *arr,int A,int B)
{
    if(arr[A]==arr[B])
        return true;
    else
        return false;
}

int show(int *arr,int sz)
{
    for(int i=0;i<sz;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;

}



int main()
{
    int sz=10;
    int arr[10];
    initialize(arr,sz);
    show(arr,sz);
    makeunion(arr,sz,2,3);
    cout<<find(arr,2,3);
    //show(arr,sz);
    return 0;

}
