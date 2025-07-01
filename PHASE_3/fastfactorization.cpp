#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
void rec(lli x, vector<lli> &arr,vector<lli> &ans){
    if(arr[x]==x)
    {
        ans.push_back(x);
    }
    else {
        ans.push_back(arr[x]);
        rec(x/arr[x],arr,ans);
    }
    return ;

}
signed main(){
    vector<lli> arr;
    arr.resize(1e6+1);
    for(lli i=1;i<=1e6;i++){
        arr[i]=i;
    }
    for(lli i=2;i<=1e6;i++){
        if(arr[i]==i){
            for(lli j=i*i;j<=1e6;j+=i){
                if(arr[j]==j)
                arr[j]=i;
            }
        }
    }
    lli n;
    cin>>n;
    for(lli i=1;i<=n;i++)
    {
        lli x;
        cin>>x;
        vector<lli> ans;
        rec(x,arr,ans);
        cout<<x<<" : ";
        for(auto y:ans){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}