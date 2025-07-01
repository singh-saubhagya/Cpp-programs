#include<bits/stdc++.h>
using namespace std;


void mergesort(string &str,int st,int en){

    if (st >= en) return;// if we don't use = sign it will go in infinite loop 

  int mid=st+(en-st)/2;
  mergesort(str,st,mid);
  mergesort(str,mid+1,en);
  
  int pt1,pt2;
  pt1=st;
  pt2=mid+1;
  string temp;
  while(pt1<=mid && pt2<=en)
  {
    if(str[pt1]<str[pt2])
    {
        temp.push_back(str[pt1]);
        pt1++;
    }
    else
    {
        temp.push_back(str[pt2]);
        pt2++;
    }

  }
  while(pt1<=mid)
  {
    temp.push_back(str[pt1]);
    pt1++;
  }
  while(pt2<=en){
    temp.push_back(str[pt2]);
    pt2++;
  }
  for(int i=0;i<temp.length();i++){
    char ch=temp[i];
    str[st+i]=ch;
  }
 

 
}
signed main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(str[i]<str[i-1])
        {
            flag=false;
        }
    }
    if(flag==false)
    mergesort(str,0,n-1);// here end is inclusive 
    cout<<str<<endl;
   
}