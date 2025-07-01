#include<bits/stdc++.h>
using namespace std;
/*
we are going to find the all the unbalanced closing brackets , if there are x unbalanced closing brackets in the n length string , so there will also be x length opening brackets present after the all the unbalance
brackets , so now we have to balance a string such that closing brackets are present in prefix and opening in the postfix, like this ]]]  [[[ 
so now if we balance a unbalance close brackets it is going to balance two closing brackets at once , so of swaps needed will only be (no of unbl closi / 2);
*/
int main(){
    string str;
    cin>>str;
    stack<int> s;
    int ans=0;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='[')
        {
            s.push('[');
        }
        else
        {
            if(s.empty()==false)
            {
                s.pop();
            }
            else 
            {
                ans++;
            }
        }
    }

    cout<<(ans+1)/2<<endl;
    return 0;
}