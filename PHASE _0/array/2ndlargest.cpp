#include<bits/stdc++.h>
using namespace std;
# define inf 1e9
// for brute force solution just sort the array and extract the element via index..






//better solution will traverse through out the array twice to find out the second largest
// This approach takes O(n) time but it iterates two times.

int findsecondlargest(vector <int> &v, int n)
{
    int max=v[0];
    int sec_larg=v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]>max)
        max=v[i];
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]<max&&v[i]>sec_larg)
        sec_larg=v[i];
    }
    return sec_larg;


}


/*
in the optimal solution take two varible larg and second large initially
 with the value of index 0 and 1 accordingly which one is greater 
 and the we iterate through out the array and update the those varibles likewise
 i.e if the value is greater than larg we update both of them and
  if it is only greater than sec_larg then only sec_larg.
  Thus only in one iteration we solve the above the give problem.
  int findsecondlargestoptimal(vector <int> &v,int n)
{
    int lg,slg;
    lg=-inf;
    slg=-inf;
    for(int i=0;i<n;i++)
    {
        if(v[i]>lg)
        {
            slg=lg;
            lg=v[i];
        }
        else if(v[i]>slg)
        {
            slg=v[i];
        }
    }
    return slg;
}
*/
int findsecondlargestoptimal(vector <int> &v,int n)
{
    int lg,slg;
    lg=-1;
    slg=-1;
    for(int i=0;i<n;i++)
    {
        if(lg==-1||v[i]>v[lg])
        {
            slg=lg;// here we are using index to store the position of the largest and second largest
            lg=i;// it would be helpful to know the postion of the first second largest in case of duplicates.
        }
        else if(slg==-1||v[i]>slg)
        {
            slg=i;
        }
    }
    return slg;
}


int main()
{
  int n,x,sec_larg;
  vector <int> v;
  cout<<endl<<"enter the size of the array"<<endl;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cout<<endl<<"enter the element at the "<< i <<'\t'<<"index"<<endl;
    cin>>x;
    v.push_back(x);
  }
  sec_larg=findsecondlargestoptimal(v,n);
  if(sec_larg==-1)
  cout<<endl<<"The second largest is not found in the array"<<endl;
  else
  cout<<endl<<"The second largest element in the array is "<<v[sec_larg]<<endl;
}