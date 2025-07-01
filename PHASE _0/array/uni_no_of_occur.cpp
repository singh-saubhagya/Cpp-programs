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
//SOLUTION 1;
 void uniqueOccurrences(int arr[],int size) 
    { 
        map<int,int> m;
        int x=0;
        vector<int> v;
        for(int i=0;i<size;i++)
        {
            if(m.find(arr[i])==m.end())
            {
                m[arr[i]]=x;
                x++;
                v.push_back(1);

            }
            else
            {
            v[m.at(arr[i])]++;       
            }
        }
        
        vector<int> check;
        


    
for(int i=0; i<v.size(); i++) {
            if(find(check.begin(), check.end(), v[i]) == check.end()) {
                check.push_back(v[i]);
                
}
}
if (v==check)
cout<<"true";
else
cout<<"false";

}
    

/*SOLUTION 2unordered_map<int,int> m;
        for(int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }
        unordered_map<int,bool> occ;

        for(pair<int,int> x : m)
        {
            int occr = x.second;
            if(occ[occr])
                return false;
            else
                occ[occr] = true;
        }
        return true;*/


    

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
    uniqueOccurrences(arr,size);
}
   