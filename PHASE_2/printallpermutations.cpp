/* Question is to print all the distint permutation of , in lexicographically order
    means 1,2,2 and 1,2,2 are same , here we use map
    , to print all the permutaions in which 1,2,2 and ,1,2,2 are different , we use multiset
 */


#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define tab '\t'
#define endl '\n'
vector<lli> arr;
map<lli,lli> m;// using global map , helps in preseving the state at every level,
lli n;
vector<lli> ans;
vector<vector<lli>> allsoln;


// every recursion has 3 parts pruning , base case and recursive case
void rec(lli level)// current level
{
    //pruning, not needed here 


    // base case
    if(level == n)
    {  
        allsoln.push_back(ans);
        return;}


//recursive case


    // iterating on all the options available in the current level
    for(auto v:m){
        // current state is i
        if(v.second>0) // checking for valid options
        {
            
            ans.push_back(v.first); 
            m[v.first]--;
            // current state is now change from i to j;

            rec(level+1);// moving to next level with the state j;

            ans.pop_back();//coming back to i state 
            m[v.first]++;//coming back to i state 

            // all these state changes and coming back is backtraking
        }
    }
}
signed main(){
    
    cin>>n;
    arr.resize(n);
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
        m[arr[i]]++;
    }
    rec(0);
    for(auto v:allsoln)
    {
        for(auto u:v)    
        {
            cout<<u<<", ";

        }
        cout<<endl;
    }
}