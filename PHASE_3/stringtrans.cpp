#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
int stringtoint(string str){
    int val=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='1'){
            int p = str.length()-1 - i;
            val+=(1<<p);
        }
    }
    return val;
}
signed main(){
    string str;
    cin>>str;
    string dest;
    cin>>dest;
    int k;
    cin>>k;
    vector<int> ban;
    ban.assign(1<<str.length(),0);
    for(int i=0;i<k;i++){
        string temp;
        cin>>temp;
        int x=stringtoint(temp);
        ban[x]=1;
    }
    
    int val1=stringtoint(str);
    int val2=stringtoint(dest);
    vector<vector<int>> g;
    g.resize(1<<str.length());
    for(int i=0;i<(1<<str.length());i++){
        for(int j=0;j<str.length();j++){
            int nw=i^(1<<j);
            // write the code to add string
            if(ban[i]==0 && ban[nw]==0)
            {
                g[i].push_back(nw);
            }

        }
    }
    vector<int> dist;
    dist.assign(1<<str.length(),inf);
    queue<int>q;
    q.push(val1);
    dist[val1]=0;
    while(q.empty()==false){
        auto x=q.front();
        q.pop();
        for(auto z:g[x]){
            if(dist[z]==inf){
                dist[z]=dist[x]+1;
                q.push(z);
            }

        }
    }
    cout<<dist[val2];

}