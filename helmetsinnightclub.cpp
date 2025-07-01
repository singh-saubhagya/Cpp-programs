#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
void enigma(){
	lli n,p;
	cin>>n>>p;
	vector<int> a,b;
	a.resize(n);
	b.resize(n);
	for(lli i=0;i<n;i++)
	cin>>a[i];
	for(lli i=0;i<n;i++)
	cin>>b[i];

	lli cost=0;
	lli rem=n;
	cost+=p;
	rem-=1;
	multiset<pair<int,int>> s;
	for(lli i=0;i<n;i++)
	{
		if(b[i]<p)
		{
			s.insert({b[i],a[i]});
		}
	}
	if(s.size()>0)
	{
		for(auto it:s)
		{
		if(rem<=0)
		break;
		lli people=it.second;
		lli ct=it.first;
		if(rem>=people)
		{
			rem=rem-people;
			cost+=people*ct;
		}
		else 
		{
			cost+=rem*ct;
			rem=0;
		}
		}
		if(rem>0)
		{
		cost+=p*rem;
		}
	}
	else 
	{
		cost=p*n;
	}
	
	cout<<cost<<endl;
}
signed main()
{
	lli t;
	cin>>t;
	while(t--)
	enigma();
}