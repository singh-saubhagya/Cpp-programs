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
void finduplicate(int arr[],int size)
{
    int freq=0,k=0;
    int dup[100];
    for(int i=0;i<size;i++)
    {
        freq=0;
        for(int j=0;j<size;j++)
        {
            if(arr[i]==arr[j])
            {
                freq++;
            }
        }
        if(freq>1)
        {
            bool flag=linearsearch(dup,k,arr[i]);
            if(flag==false)
            {
            dup[k]=arr[i];
            k++;
            }
        }
    }
    printarray(dup,k);
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
    finduplicate(arr,size);
}