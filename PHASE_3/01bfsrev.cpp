#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'
#define inf 1e9
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<lli,lli>>> g;
    g.resize(n+1);


    for(lli i=0;i<m;i++){
        lli a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    vector<bool> marked(n+1,false);

    vector<lli> dis(n+1,inf);

    deque<lli> dq;
    dq.push_back(1);
    dis[1]=0;// always remember this part
    while(dq.empty()==false)
    {
        int  x=dq.front();
        dq.pop_front();
        if(marked[x])// use of this marked is necessary because every time we are popping element we are getting the shortest distance , and next time if we get any distance would be greater than the prev one , and there is no need of relaxing the edge with the greater distance.
        continue;
        marked[x]=true;
        
        for(auto z:g[x])
        {
            lli a=z.first;// node
            lli b=z.second;// weight
            lli dt=dis[x]+b;
            // this is called relaxing the edge.
            if(dt<dis[z.first]) // why didn't we check dis[z.first]==inf and relax it . because the edge weight of z and x could be 1 or 0 .  Suppose  there can exist n1 , and n2 whose min dist with s is same but has n1->x has edge of 1 and n2->x has edge of 0 , thus in future there can be a need of relaxtain if n1 got popped before n2.
            {
                dis[z.first]=dt;
                if(b==0)
                {
                    dq.push_front(a);// if it is 0 then this dt is again minimum among all the other dt in the deque. so next time this will pop again , therefore keeping it in front.
                }
                else
                {
                    dq.push_back(a);// it it is 1 , then the distance of at would be greater than to the all the distance or equal(with max distance in the dequeu), 
                    //because if it would have been smaller it should be present in the queue already, therefor adding in to the most last pn .
            }
        }
        }
    }
    for(lli i=1;i<=n;i++){
        cout<<dis[i]<<" "<<endl;
    }
    
}