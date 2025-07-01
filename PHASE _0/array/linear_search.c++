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
bool linearsearch(int arr[], int size,int x)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int size,x;
    bool flag;
    cout<<"INPUT THE SIZE OF THE ARRAY"<<'\t';
    cin>>size;
    int arr[100];
    for(int i=0;i<size;i++)
    {
        cout<<endl<<"ENTER THE ELEMENT AT THE "<<i<<" INDEX"<<'\t';
        cin>>arr[i];
    }
    cout<<"Enter the element you want to search"<<'\t';
    cin>>x;
    flag=linearsearch(arr,size,x);
    if(flag==1)
    cout<<"Element is present in array";
    else
    cout<<"Element is not present in array";
}