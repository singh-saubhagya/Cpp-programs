
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
/*seive of Eratosthenes(eh·ruh.taas·thuh·neez) 

it is used to find the all the prime no in the range {1 , 1e7} in time complexity of nlog(log(n)), 

*/ 
void findprime_1(vector<lli > arr){
    for(lli  i=2;i<=1e7;i++){
        if(arr[i])// if it is set already set  to 1 , then it is a prime no, therefore we are now going to mark the multiples of this no as not prime 
        {
            for(lli  j=2*i;j<=1e7;j+=i){
                arr[j]=0;
            }
        }
    }
    for(lli  i=1;i<=30;i++)
    {
    if(arr[i])
    {
        cout<<i<<endl;
    }
    }
}


void findprime_2(vector<lli > arr)
{
    for(lli  i=2;i<=1e7;i++){
        if(arr[i])// if it is set already set  to 1 , then it is a prime no, therefore we are now going to mark the multiples of this no as not prime 
        {
            for(lli  j=1LL*i*i;j<=1e7;j+=i){// refer to notes , to know how this optimization works
                arr[j]=0;
            }
        }
    }


for(lli  i=1;i<=30;i++)
    {
    if(arr[i])
    {
    cout<<i<<endl;
    }
    }
}
signed main(){
 vector<lli > arr;
 arr.assign(1e7 +1 ,1);
 arr[1]=0;// 1 is not a prime no .
//  findprime_1(arr);// without making optimization 
 findprime_2(arr);// with optimization 
 
}