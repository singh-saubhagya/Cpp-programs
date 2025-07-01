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
/*void duplicates(int nums [],int size)
{
    unordered_map<int,int> m;
        for(int  it=0;it<size;it++)
        {
            m[nums[it]]++;

        }
        vector<int> v;
        for(auto it= m.begin();it!=m.end();it++)
        {
            if((*it).second==2)
            {
                v.push_back((*it).first);
            }
        }
         for(int  it=0;it<v.size();it++)
            cout<<endl<<v[it];
         }
*/
void duplicate(int arr[],int size)
{

    vector<int> v;
    for(int i=0;i<size;i++)
    {
        int index=abs(arr[i]);
        if(arr[index]<0)
        {
            v.push_back(abs(arr[i]));
        }
        else
        {
            arr[index]=arr[index]*(-1);
        }


    }
    for(int  it=0;it<v.size();it++)
            cout<<endl<<v[it];
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
     duplicate(arr, size);
}