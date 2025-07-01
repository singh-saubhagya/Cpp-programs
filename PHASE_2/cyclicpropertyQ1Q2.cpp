#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
#define tab '\t'
#define endl '\n'  
vector<lli> pos;
string findbits(lli x) {
    if (x == 0) return "0"; 

    string str = "";
    while (x != 0) {
        str += (x & 1) ? '1' : '0'; 
        x=x>>1; 
    }
    
    reverse(str.begin(), str.end());
    return str;
}
void solve(){
    string s;
    for(lli i=0;i<=1e5;i++){
        string str=findbits(i);
        s+=str;
    }

  
    for(lli i=0;i<s.length();i++){
        if(s[i]=='1'){
            pos.push_back(i);
        }
    }

}

void enigma(lli x)
{
    cout<<pos[x-1]<<endl;
}
int main()
{
    solve();
    lli q;
    cin>>q;
    for(lli i=0;i<q;i++){
        lli x;cin>>x;
        enigma(x);
    }
   
}


// better approach


// #include <bits/stdc++.h>
// using namespace std;

// int countsetbits(int i) {
//     int ct = 0;
//     while (i > 0) {
//         if (i & 1)
//             ct++;
//         i = i >> 1;
//     }
//     return ct;
// }
// int countbits(int i){
//     if(i==0)
//     return 0;
//     int ct=0;
//     while(i)
//     {
//         ct++;
//         i=i>>1;
//     }
//     return ct;
// }
// signed main() {
//     int k;
//     cin >> k;

//     int pt = 0;
//     set<pair<int, int>> s;// we didn't used map because the find  operation of the map searches by key and we want to search by value 

//     for (int i = 0; i <= 1e5; i++) {
//         int ct = countsetbits(i);
//         s.insert({ pt + ct,i}); 
//         pt = pt + ct;  
//     }
//     int idx=0;
//     auto it = s.lower_bound({k,-1});
//     int ct=countbits(it->second);
  
//     for(int i=1;i<ct;i++)
//     {
//         int a=1<<(i-1);
//         int b=(1<<(i))-1;
//         int c=b-a+1;
       
//         idx=idx+c*i;
//     }
  
//     int ans;
//     for(auto x:s)
//     {
//         if(x.second==(1<<(ct-1))-1)
//         {
//             ans=x.first;
//         }
//     }
   
//     for(int i=(1<<(ct-1));i<=((1<<(ct))-1);i++)
//     {
//         if(ans==k)
//         {
//             break;
//         }
//         bitset<21> x(i);
//         for(int j=ct-1;j>=0;j--)
//         {
//             idx++;
            
//             if(x[j]==1)
//             {
//                 ans++;
//                 if(ans==k)
//                 {
//                     break;
//                 }
//             }
//         }
//     }
//     cout<<idx<<endl;
//     // for (auto x : s)
//     //     cout << x.first << " " << x.second << endl;

  
//     // auto it = s.lower_bound({k, -1});  

//     // if (it != s.end())
//     //     cout << it->second << endl;
//     // else
//     //     cout << "Not found" << endl;  
// }
