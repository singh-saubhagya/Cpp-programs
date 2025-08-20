/*
This is the classis matrix multiplication problem, 

It can be solved using form 4 , where we define l to r as subarray, and then find best partition for it. 
Why form 4 only, because form 2 can't be used here as multiplication of matrix will result in new matrix , new matrix will also be used in further operations, which we can't handle in form 2.

also the adjacent nature of multiplication of matrix is also reason of form 4.

*/


#include<bits/stdc++.h>
using namespace std;
using pp = pair<int,int>;
#define inf 1e9
vector<pair<int,int>> dim;
int nn;
int dp[102][102];


int rec(int l,int r)
{
    if(l<0 || r>nn-1)
    return inf;

    if(l>r)
    return inf;

    if(l==r)// this is the base case when we have only 1 matrix so no cost needed.
    return 0;

    if(dp[l][r]!=-1)
    return dp[l][r];

    int ans=inf;
    for(int i=l;i<r;i++)
    {
        ans=min(ans,rec(l,i)+rec(i+1,r)+dim[l].first*dim[r].second*dim[i].second);// resulting matrix will have dimension as row=matix at l th pn, col=matrix at rth pn, common col=col of matrix at ith pn
    }
    return dp[l][r]=ans;

}
vector<pair<pp,pp>> gene;

void generate(int l,int r)
{
    if(l==r)
    return; 
    int ans=inf;
    int pt=-1;
    for(int i=l;i<r;i++)
    {
        int temp=rec(l,i)+rec(i+1,r)+dim[l].first*dim[r].second*dim[i].second;
        if(temp<ans)
        {
            pt=i;
            ans=temp;
        }
    }
    pp a= {dim[l].first,dim[pt].second};
    pp b= {dim[pt+1].first,dim[r].second};
    gene.push_back({a,b});
    generate(l,pt);
    generate(pt+1,r);
    return;
}
signed main()
{
    int n;
    cin>>n;
    vector<int> arr;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    for(int i=1;i<n;i++)
    {
        int row=arr[i-1];
        int col=arr[i];
        dim.push_back({row,col});
    }
    nn=dim.size();
    cout<<rec(0,nn-1)<<endl;;
    generate(0,nn-1);
    for(auto x:gene)
    {
        pp a=x.first;
        pp b=x.second;
        cout<<"["<<a.first<<","<<a.second<<"]"<<" * "<<"["<<b.first<<","<<b.second<<"]"<<endl;
    }

}