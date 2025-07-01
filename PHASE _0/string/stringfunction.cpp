#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    string str,opt;
    cin>>n>>x;
    cin>>str;
    

    string arr[x];
    string result[x];
    int j=0;
    for(int i=0;i<x;i++)
    {
        cin>>opt;
        if(opt=="pop_back")
        {
            n--;
        }
        if(opt=="front")
        {result[j]=str[0];j++;}
    
        if(opt=="back")
        { result[j]=str[n-1];
        j++;}
        if(opt=="sort")
        {
            int l,r;
            cin>>l>>r;
            if(l>r)
            {
                int temp=l;
                l=r;
                r=l;
            }
            sort(str.begin()+l-1,str.begin()+r);


        }
        if(opt=="reverse")
        {
        int l,r;
            cin>>l>>r;
            if(l>r)
            {
                int temp=l;
                l=r;
                r=l;
            }
        reverse(str.begin()+l-1, str.begin()+r);
        }
        if(opt=="print")
        {
            int a;
            cin>>a;
            result[j]=str[a-1];j++;
            
        }
        if(opt=="substr")
        {
        int l,r;
            cin>>l>>r;
            if(l>r)
            {
                int temp=l;
                l=r;
                r=l;
            }
            result[j]=str.substr(l-1,r-l+1);
            j++;



        }
        if(opt=="push_back"){
                char ch;
                cin>>ch;
                str=str+ch;
                n++;

        }
        
        }
        for(int i=0;i<j;i++)
        {
            cout<<endl<<result[i];
        }
}
