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
void findunique(int arr[],int size)
{
    int uni[100],k=0;
    int freq=0;
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
        if(freq==1)
        {
            uni[k]=arr[i];
            k++;
        }
    }
    printarray(uni,k);
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
    findunique(arr,size);
   
    return 0;

}