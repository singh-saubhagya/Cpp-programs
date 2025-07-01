#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define  tab '\t'
#define endl '\n'

lli n;
multiset<lli> arr;
void enigma()
{
    cin>>n;
    n=1<<n;
    for(lli i=0;i<n;i++){
        lli x;
        cin>>x;
        arr.insert(x);
    }
    vector<lli> sg;// to store sum genated till now;
    vector<lli > ans;
    sg.push_back(0);
    arr.erase(arr.find(0));
    while(arr.size()!=0)
    {
        lli sml=*arr.begin();
        ans.push_back(sml);
        vector<lli> temp;
        for(auto x:sg){
            temp.push_back(x+sml); arr.erase(arr.find(x+sml));
        }
        for(auto x:temp)
        {
            sg.push_back(x);
           
        }
        
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}
signed main(){
    lli t;
    cin>>t;
    while(t--){
        enigma();
    }    
}