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
}