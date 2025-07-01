
#include <bits/stdc++.h>
using namespace std;


vector<pair<int ,int >> ng={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,-2},{-1,2}};
int  KnightWalk(int  N, int  Sx, int  Sy, int  Fx, int  Fy)
{
    Sx--;
    Sy--;
    Fx--;
    Fy--;

    vector<vector<int >> vis(N,vector<int >(N,-1));
	queue<pair<int ,int >> q;
    q.push({Sx,Sy});
    vis[Sx][Sy]=0;
    if(Sx==Fx && Fy== Sy)
    return 0;
    while(q.empty()==false)
    {
        pair<int ,int > x=q.front();
        q.pop(); 
        
        for(auto y:ng){
            int  row=y.first+x.first;
            int  col=y.second+x.second;
            if(row>=0 && row<=N-1 && col>=0 && col<=N-1){
              
              
                if(vis[row][col]==-1)
                {
                   
                    vis[row][col]=vis[x.first][x.second]+1;
                    q.push({row,col});
                    if(row==Fx && col == Fy)
                    return vis[row][col];
                }
            }
        }
    }
    return -1;

}


signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int  test_case;
	cin >> test_case;

	while (test_case--)
	{
		int  N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
