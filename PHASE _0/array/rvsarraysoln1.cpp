#include<bits/stdc++.h>
using namespace std;
void reverse_array(int arr[],int size)
{
    int half,temp;
    half=size;
    if(size&1)
    half=half/2;
    else
    half=half/2-1;
    for(int i=0;i<=half;i++)
    {
        temp=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
    }
    
}
void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<'\t';
    }
    cout<<endl;
}
int main()
{
    int size;
    cin>>size;
    cout<<endl;
    int arr[100];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
        cout<<endl;
    }
    printarray(arr,size);
    reverse_array(arr,size);
    printarray(arr,size);
}