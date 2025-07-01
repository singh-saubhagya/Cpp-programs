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

int findunique(int arr[], int size)
{
    int uni=arr[0];
    for(int i=1;i<size;i++)
    {
        uni=uni^arr[i];
    }
    return uni;
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
    int uni=findunique(arr,size);//applicable only when 1 unique element is presenet in the array 
    cout<<"The unique element in the array is" <<'\t'<<uni;
}