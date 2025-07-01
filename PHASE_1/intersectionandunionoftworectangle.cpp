#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define tab '\t'
#define endl '\n'
lli area_of_rectangle(lli a, lli b , lli c , lli d)
{
    lli len=c-a;
    lli breath=d-b;
    len=abs(len);
    breath=abs(breath);
    return len*breath;

}
int main()
{
    lli t;
    cin>>t;
    lli x1,y1,x2,y2,x3,y3,x4,y4;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        lli area=0;
        //finding coordinates of intersection area
            lli a=max(x1,x3);
            lli c=min(x2,x4);
            lli b=max(y1,y3);
            lli d=min(y2,y4);
        if(a<c && b<d)// intersection is there between rectangle
        {
            
            
            area=area_of_rectangle(a,b,c,d);

        }
        else
        {
            area=0;// no intersection
        }
            lli area1=area_of_rectangle(x1,y1,x2,y2);
            lli area2=area_of_rectangle(x3,y3,x4,y4);
            cout<<area<<" "<<area1+area2-area<<endl;
    }
    

}