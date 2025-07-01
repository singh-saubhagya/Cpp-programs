#include<bits/stdc++.h>

using namespace std;
void quicksort(vector<int>&arr,int st, int en)
{
    int pivot=st;
    if(st>=en)
    return;
    for(int i=st+1;i<en;i++)
    {
        if(arr[i]<arr[pivot])
        {
        
            
                    // copy  pivot +1 to current j
                    // pivot with j
                    // copy the current pivot value at pn pivot+ 1 
                    int x=arr[pivot];
                    arr[pivot]=arr[i];
                    arr[i]=arr[pivot+1];
                    arr[pivot+1]=x;
                    pivot++;
               
            
        }
    }
    quicksort(arr,st,pivot);// doing pivot and not pivot -1 because the for loop in quicsort is exclusive for the ending index
    quicksort(arr,pivot+1,en);
    
}
signed main(){
    int l;
    cin>>l;
    string str;
    cin>>str;
  
    vector<int> arr;
    for(int i=0;i<l;i++)
    arr.push_back((int)str[i]);
    quicksort(arr,0,l);
    for(int i=0;i<l;i++)
    cout<<char(arr[i]);
}