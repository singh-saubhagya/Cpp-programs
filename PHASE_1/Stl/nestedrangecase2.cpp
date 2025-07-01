#include<bits/stdc++.h>
using namespace std;


/*
Problem: We have sequence of queries consisting of inseting intervals and the
another of checking some point x lies inside the interva|
Brute force approach:
we maintan two diff vectors one for lower limit and second for upper limit of the interval and every time we get an interval insertion query
we add update these vectors and sort them and then use case 1 approach to solve . 




Optimal approach:
We are using set with pair datatype as its elements.
So what we are doing is we are just maintainig those intervals which are neither subset of any other in the set.
How we are doing?
We are not inserting those intervals which are totally covered in the existing inserted interval.
We are earsing all those intervals if we found some interval which covers all those intervals at once.

in set we know all the intervals[a,b][c,d][e,f] are sorted like a<c<e and b<d<f 

Time complexity is O(qlogn) q is the no of queries and n is no of intervals

nlogn for the covering_intl fn 
thererfore total time complexity is nlogn + qlogn ~~ qlogn 
Amortized time complexity is average case tc
which is qlogn/q=logn for this problem

*/

#define inf 1e9
set <pair<int ,int >> interval;
void covering_intl(int l,int r)// fn to erase all the intervals inside [l,r]
{   
    auto lb=interval.lower_bound({l,-inf}); /* lower bound :to find the first interval inside l,r  and we are using -inf because 
        we want to find lower limit of that interval which is just greater or equal to l 
        Time complexity in worst case will be if we last inteval is covering all the remaining interval.
        Thus if there were a total of n intervals T.C to erase intervals will nlogn 
        
        */
    while(1)
    {
        if(lb==interval.end())
        break; // not found 
        if(lb->second<=r)
        interval.erase(lb); // removing those inside l,r
        else 
        break;
    }
}   
bool covered_by_inl(int l,int r)//this fn is called for all the q queries therfore TC will be qlogn
{
    auto lb=interval.upper_bound({l,inf});// to find the lower limit just greater than the l
    if(lb==interval.begin())
    return false;
    lb--;//doing --lb because this iterator will point to the interval where the lower limit is equal or less than the l which helps in determing the coverage;
    
    if(lb->second>=r)
    {
        return true;
    }
    return false;
}
void insert(int l,int r)
{
    if(!covered_by_inl(l,r))
    {
        covering_intl(l,r);
        interval.insert({l,r});
    }
}
int main()
{
    int q;
    char ch;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>ch;
        if(ch=='+')
        {
            int a,b;
            cin>>a>>b;
            insert(a,b);
        }
        else
        {
            int x;
            cin>>x;
            
            bool flag=covered_by_inl(x,x);
            if(flag==true)
            cout<<endl<<"Point is covered in the interval";
            else 
            cout<<endl<<"Point is not covered in the interval";            
        }

    }

}