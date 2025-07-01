#include<bits/stdc++.h>
using namespace std;
void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<'\t';
    }  
    cout<<endl;
}
void swap(int arr[],int i)
{
    int temp=arr[i];
    arr[i]=arr[i+1];
    arr[i+1]=temp;
}
int swapalternate(int arr[],int size)
{
    for(int i=0;i<size;i+=2)
    {
        if(i+1<size)
        {
            swap(arr,i);
        }
    }
}

int main()
{
    int size;
    cout<<"INPUT THE SIZE OF THE ARRAY"<<'\t';
    cin>>size;
    int arr[100];
    for(int i=0;i<size;i++)
    {
        cout<<endl<<"ENTER THE ELEMENT AT THE "<<i<<" INDEX"<<'\t';
        cin>>arr[i];
    }
    printarray(arr,size);
    swapalternate(arr,size);
    printarray(arr,size);
}