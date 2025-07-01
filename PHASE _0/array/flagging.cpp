#include<bits/stdc++.h>
using namespace std;
//Problem is to find the no. >=1 i.e not present in the array


/*
In this solution we are making freq array.
*/
void printarray(vector<int> v,int n)
{
   cout<<endl;
   for(int i=0;i<n;i++)
   {
     cout<<'\t'<<v[i];
   }
   cout<<endl;
}
int soln1(vector <int> &v, int n)
{
    vector<int > z;
    for(int i=0;i<=n+1;i++)
    {
        z.push_back(0);
    }
    for(int i=0;i<n;i++)
    {
        z[v[i]]++;
    }
    for(int i=1;i<=n+1;i++)
    {
        if(z[i]==0)
        return i;
    }
}
 
/*
In the flagging solution we are not using freq array in place of this we are using flagging which is
if any integer v[i] we are getting we are making the integer with the index v[i] negative which denotes
and if the no v[i] is greater than the size of the array we directly make the integer negative i.e -v[i]
This is the most optimal solution with time complexity O(n) and space complexity is O(1)
 */
int  flaggingsoln(vector <int > &v, int n)
{
    for(int i=0;i<n;i++)
    {
        if(v[i]>n)
        v[i]=v[i]*(-1);
        else if(v[abs(v[i])-1]>0)
        v[abs(v[i])-1]=v[abs(v[i])-1]*-1;
    }
    
    printarray(v,n);
    
    for(int i=0;i<n;i++)
    {
        if(v[i]>0)
        {
        return i+1;
        }
        

    }    
            return n+1;


}
int main()
{
    
    int n,x;    
    vector<int> v;
    cout<<endl<<"input the size of the array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cout<<endl<<"input the element at the "<<'\t'<<i<<'\t'<<"index"<<endl;
      cin>>x;
      v.push_back(x);   
    }
    //int k=soln1(v,n);
    int k=flaggingsoln(v,n);
    cout<<endl<<"The missing no in the array greater equal to 1 is "<<'\t'<<k;


}