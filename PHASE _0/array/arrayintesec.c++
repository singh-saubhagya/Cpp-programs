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
//brute force solution 
void findintersection(int arr1[], int size1, int arr2[], int size2)
{
    int insec[100];
    int k=0;
    for(int i=0;i<size1;i++)
    {
        for( int j=0;j<size2;j++)
        {
                if(arr1[i]==arr2[j])
                {
                    insec[k]=arr1[i];
                    k++;
                    break;
                }
        }
    }
    printarray(insec,k);
}
/* optimal solution 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
       // unordered_map<int,int> m;
        int arr[1000]={0};
        for(int i=0;i<nums1.size();i++)
        {
            if(arr[nums1[i]]==0)
            arr[nums1[i]]++;

        }
        vector<int> v;
         for(int i=0;i<nums2.size();i++)
        {
            if(arr[nums2[i]]==1)
            {   
                arr[nums2[i]]++;
                v.push_back(nums2[i]);
            }
             
        }
        return v;
        
        
    }
};*/

int main()
{
    int size1,size2;
    int arr1[100],arr2[100];
    cout<<"Input the size for array 1"<<'\t';
    cin>>size1;
    cout<<"Input the size for array 2"<<'\t';
    cin>>size2;
    cout<<"Takin input for arrary 1:"<<endl;
    for(int i=0;i<size1;i++)
    {
        cout<<"enter the element at the "<< i<< " index"<<'\t';
        cin>>arr1[i];
    }
    cout<<"Taking input for arrary 2:"<<endl;
    for(int i=0;i<size2;i++)
    {
        cout<<"enter the element at the "<< i<< " index"<<'\t';
        cin>>arr2[i];
    }
    printarray(arr1,size1);
    printarray(arr2,size2);
    findintersection(arr1,size1,arr2,size2);
    return 0;

    
}