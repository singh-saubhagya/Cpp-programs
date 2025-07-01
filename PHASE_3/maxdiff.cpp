#include<bits/stdc++.h>
using namespace std;
void dfs(int node ,int maxval,int minval,int pnt,vector<vector<int>> &g,vector<int> &val){
	int ans=max(abs(val[node]-maxval),abs(val[node]-minval));
	cout<<"Node : "<<node<<" evaluates to : "<<ans<<endl;
	for(auto x:g[node]){
		if(x!=pnt){
			dfs(x,max(maxval,val[node]),min(minval,val[node]),node,g,val);
		}
	}
}
signed main(){
	int n;
	cin>>n;
	vector<vector<int>> g;
	g.resize(n+1);
	vector<int> val;
	val.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	for(int i=1;i<=n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,val[1],val[1],0,g,val);
}