
/*

case 1:  Intervals followed by  q no.

Problem: We are given a sequence of intervals on the real line followed by a no. x and we have to 
to determine whether this no. lies in the above intervals or not.
So the most optimal approach is we are first counting the no. of intervals which are not covering the 
no. HOW? by storing the intial range l and the final range u in seperate vector datatypes 
if the no is greater than the u or no is less the l it won't lie in that interval 
so we use lower bound on the vector ur to know all the u's  which are less than x and upper bound on the 
vector lr to know the first l which is greater than the element x and then subtracting it with the size of the 
lr to know the no of such l.


The below solution is the most optimal solution with time complexity O(nlogn+qlogn) space complexity is also O(n)
we can also use vector inplace of set but then we need to sort it will alter the time complexity to be O(NlogN)


we can't use set or map as it does't store duplicates elements also it takes logn time for each insertion.

*/
#include<bits/stdc++.h>
using namespace std;
vector<int> lr,ur;
int x,n;
void checkinrange()
{
    auto ub=upper_bound(lr.begin(),lr.end(),x)-lr.begin();
    auto lb=lower_bound(ur.begin(),ur.end(),x)-ur.begin();

    int l=lr.size()-ub;
    
    int u=lb;

    int soln=n-l-u;
    cout<<soln;
    
    

}
int main()
{
    int u,l;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>u;
        ur.push_back(u);
        lr.push_back(l);

    }
    sort(lr.begin(),lr.end());
    sort(ur.begin(),ur.end());
    int q;
    cin>>q;
    while(q--)
    {
    cin>>x;
    checkinrange();
    }
}


/*
This is the brute force approach with time complexity O(n*q)


*/
// #include<bits/stdc++.h>
// using namespace std;
// struct interval{
//     int l;
//     int u;
// };
// int main()
// {
//     int a,b,x;
//     int n;
//     cin>>n;
//     interval arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a>>b;
//         arr[i].l=a;
//         arr[i].u=b;
        
//     }
//     int q;
//     cin>>q;
//     while(q--)
//     {
//     cin>>x;
//     int count=0;
//     for(int i=0;i<n;i++)
//     {
//         if(x>= arr[i].l&& x<=arr[i].u)
//         {
//             count++;
//         }
//     }
//     cout<<count;
//     }
// }

