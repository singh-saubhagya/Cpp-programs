#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n';
#define  tab '\t';


vector<lli> arr;
vector<vector<lli>> psum;
lli n;
void psumarray(){
    psum=vector<vector<lli>>(33,vector<lli>(n+3,0));
    for(lli i=0;i<32;i++){
        for(lli j=1;j<=n;j++)
        {
            if((arr[j-1]>>i)&1)
            {
                psum[i][j]=1;
            }
        }
    }
    for(lli i=0;i<32;i++){
        for(lli j=1;j<=n;j++)
        {
            psum[i][j]+=psum[i][j-1];
        }}
    
}
void enigma(){
    
    cin>>n;
    arr.resize(n);
    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }
    psumarray();
    lli q;
    cin>>q;
    while(q--){
        lli l,r;
        cin>>l>>r;
        double range=r-l+1;
        lli x1=0,x2=0,x3=0;
        for(lli i=0;i<32;i++){
            lli stbits=psum[i][r]-psum[i][l-1];
            if(stbits<(range/2.0)){
                x1+=(1LL<<i);

            }
            if(stbits!=(r-l+1))
             x2+=(1LL<<i);
           if(stbits)
             x3+=(1LL<<i);

        }
        lli ans=x1+x2+x3;
        cout<<ans<<endl;
    }

}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  lli t;
  cin>>t;
  while(t--)
  enigma();

    // while(1){
    //     arr.resize(n);
    //     for(lli i=0;i<10;i++){
    //         lli x=abs(rand()%10);
    //         arr[i]=x;
    //     }
    //     vector<lli> a=enigma();
    //     vector<lli> b=correctsoln();
    //     if(a!=b)
    //     {pr(arr);pr(a);pr(b);
    //     break;}
    // }

}