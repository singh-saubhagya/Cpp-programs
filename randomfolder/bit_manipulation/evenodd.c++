#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,k;
    cout<<"enter the value of n";
    cin>>n;
    vector<int> even,odd;
    for(i=1;i<=n;i++)
    {
        cout<<"enter the number\n";
        cin>>k;
        if(k%2==0)
        {
            even.push_back(k);
        }
        else
        {
            odd.push_back(k);
        }


    }
        for(i=0;i<even.size();i++)
        {
            cout<<even[i];
        }
        cout<<"\n";
        for(i=0;i<odd.size();i++)
        {
            cout<<odd[i];
        }

    
}
