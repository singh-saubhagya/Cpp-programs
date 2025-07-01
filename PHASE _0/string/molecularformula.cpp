#include<bits/stdc++.h>
using namespace std;
stack <int> s;
string str;
map<int ,int> brac;

void brackets()
{
    
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
        s.push(i);
        }
        else if(str[i]==')')
        {
            brac[s.top()]=i;
            s.pop();
        }
    

    }
 
    
}

map<string,int> merge(map<string,int> temp1, map<string,int> temp2)
{
    map<string,int> temp3=move(temp1);

    for(pair<string,int> x:temp2)
    {
        if(temp3.find(x.first)!=temp3.end())
        temp3[x.first]+=x.second;
        else
        temp3[x.first]=x.second;
    }
    return temp3;
}
map<string,int> parseelement(int st,int en)
{
            map<string,int> freq;
            int num=0;
            int end=en;
            while(end>=st && isdigit(str[end]))
            {
                num++;
                end--;
            }
            if(num>0)
            {
            int no=stoi(str.substr(end+1,num));
            freq[str.substr(st,end-st+1)]=no;   
            }
            else 
            freq[str.substr(st,end-st+1)]=1;
            cout<<endl;
            
            return freq;


}
map<string,int> parsestring(int st,int en)
{
    if(st>en)
    {    
    map<string,int> p;
    return p;
    }
    map<string,int> temp3;
      
        if(str[st]=='(')
        {
            int ending=brac[st];
            
            int pos=ending;
            int num=0;
            map<string,int> temp1=parsestring(st+1,ending-1);  
            ending++;
            while(ending<=en && isdigit(str[ending++]))
            {
                num++;
            }
            
            int no;
            if(num>0)
            {
            int no=stoi(str.substr(pos+1,num));
            }
            else
            no=1;
            for(pair<string,int> x:temp1)
            {
                x.second*=no;
               
                
            }
           
             map<string,int> temp2=parsestring(pos+1+num,en);
            
             temp3=merge(temp1,temp2);
             return temp3;
            
        }
        else if(isupper(str[st]))
        {
            int pos=st+1;
            while(pos<=en && (islower(str[pos]) || isdigit(str[pos])))
            {
            pos++;
            }
            map<string,int> temp1=parseelement(st,pos-1);
            map<string,int> temp2=parsestring(pos,en);
            temp3=merge(temp1,temp2);
            return temp3;

            

        }
        return temp3;
        
        
    
    return temp3;
}

int main()
{
    cin>>str;
    
    brackets();
    map<string,int> freq=parsestring(0,str.size()-1);
    for(pair<string,int>x:freq)
    {
        cout<<x.first<<x.second;
    }

}