#include<bits/stdc++.h>

using namespace std;
 int  main()
 {
    int q;
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>q;
    vector <int> result;
    while (q--)
    {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);

        }
        int dif,pdif=v[1]-v[0];
        int size=2,longest=0;
        for(int i=2;i<n;i++)
        {
            dif=v[i]-v[i-1];
            if(dif==pdif)
            {
                size++;
            }
            else
              { pdif=dif;
               longest=max(longest,size);
               
               size=2;
               }

        }
        longest=max(longest,size);
        result.push_back(longest);
        v.clear();
    }
        for(int i:result)
        cout<<i<<endl;
    


}
 