#include<bits/stdc++.h>
using namespace std;

struct student
{
    int size;
    vector <int > o;
    vector <int > p;
    
};
/*
brute force approach is doing linear search

better solution is using frequency array


This is the most optimal solution in which we are taking xor of all the elements of the original array
and storing in x variable. After this we are taking xor of the elements of permuted array with the same 
variable x so after all the iterations if we get the resultant xor to be = to 0 then it is a permutation of 
the original array.


*/

void checkpermutation(int n,student arr[])
{
    int x,size;
    for(int i=0;i<n;i++)
    {
        x=0;
        size=arr[i].size;
        for(int j=0;j<size;j++)
        {
            x=x^(arr[i].o[j]);
        }
        for(int j=0;j<size;j++)
        {
            x=x^(arr[i].p[j]);
        }
        if(x==0)
        cout<<endl<<"yes"<<endl;
        else
        cout<<endl<<"no"<<endl;
        
        
    }
}

int main()
{
    int n,size,x;
    cin>>n;
    student arr[10];
    for(int i =0;i<n;i++)
    {
        cin>>size;
        arr[i].size=size;

        for(int j=0;j<size;j++)
        {
            cin>>x;
            arr[i].o.push_back(x);
        }
        for(int j=0;j<size;j++)
        {
            cin>>x;
            arr[i].p.push_back(x);
        }

    }   
    checkpermutation(n,arr);
}