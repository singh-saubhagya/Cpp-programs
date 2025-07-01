#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define  endl '\n'
#define tab '\t'

int main(){
    vector<lli> arr={23, 23, 4, 3, 5, 3, 15, 15};
    //  find xor of all the elemensts
    lli n=arr.size();
    lli ans=0;
    for(lli i=0;i<n;i++){
        ans^=arr[i];
    }
    lli x=ans&(~(ans-1));
    lli n1=0,n2=0;
    for(lli i=0;i<n;i++){
        if(arr[i]&x)
        {
            n1^=arr[i];
        }
        else
        n2^=arr[i];
    }
    cout<<n1<<tab<<n2<<endl;
}
