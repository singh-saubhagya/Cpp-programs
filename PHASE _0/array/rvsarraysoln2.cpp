#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int s,int e)
{
    int temp=arr[s];
    arr[s]=arr[e];
    arr[e]=temp;
}
 void reverse_array(int arr[] ,int size)
{
    int s,e;
    s=0;
    e=size-1;
    while(s<e)
    {
        swap(arr,s,e);
        s++;
        e--;
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