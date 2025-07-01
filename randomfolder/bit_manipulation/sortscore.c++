#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,marks;
    cout<<"enter the no of students\n";
    cin>>n;
    string str;
    pair<string,int>p[n];
    for(i=0;i<n;i++)
    {
        cout<<"\nenter the name of the student and score\n";
        cin>>str;
        cin>>marks;
        p[i]={str,marks};

    }
    sort(p,p+n);
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<(p[i]).first<<"\t"<<(p[i]).second<<"\n";
    }


}