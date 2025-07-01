#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,x,score;
    cin>>n;
    vector <int> v,v1;
    for(int i=1;i<=n;i++)
    {
        score=0;
        cin>>k;
        for(int j=1;j<=2*k;j++)
        {
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        for(int c=0;c<k;c++)
        {
            int n1=min(v[2*c],v[2*c+1]);
            score=score+n1;
        }
            v1.push_back(score);


    }
    for(int o:v1)
    {
        cout<<o<<"\n";
    }


}