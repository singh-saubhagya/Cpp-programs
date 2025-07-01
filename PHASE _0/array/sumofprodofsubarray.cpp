#include<bits/stdc++.h>
using namespace std;
//HERE WE CAN'T USE CONTRIBUTION TECHNIQUE DUE TO DIFF OF SIGNS BETWEEM ELEMENTS AND SUBARRAY



/*
This is the brute force approach
where we have seperate loops for the staring and ending points 
`and again one loop to find the product of the subarray
int prodarray(vector<int> &v,int n)
{
    int sum=0;
    for(int st=0;st<n;st++)
    {
        for(int en=st;en<n;en++)
        {
            int pro=1;
            for( int i=st;i<=en;i++)
            {
                pro=pro*v[i];
            }
            sum=sum+pro;
        }
    }
    return sum;
}

Better soln

 with time complexity O(n^2)
    int prodarray(vector<int> &v,int n)
{
    int sum=0;
    int pro=0;
        for(int en=0;en<n;en++)
        {
            pro=pro*v[en]+v[en];
            sum=pro+sum;
        }
    
    return sum;
}

}
*/

/*
This is the most optimal solution of the problem with time complexity O(n)
here we are iterating to each element and treating it like the end point of the subarray and
finding all the possible subarray say for example 1 , 2 , 3 , 4 
when we are at 2 we have 2 possible subarray 2 and 1,2 hence to find the sum of the prod 
we have taken a varible pro which will multiply the old subarray with the ongoing end point and 
and add the ongoing element
here we have multiply 1 by 2 and add 2 to find the sum of the product of the subarray ending with 2 
hence for any ith element to find its sum of the product of the subarray we will just multiply the ith
element to the previous sum of prod subarray and add the ith element.
And then we have taken a sum varaible which will add the prev sum of prod to the new sum of prod
*/
signed main(){
    int n;
    cin>>n;
    vector<int> arr;
    arr.resize(n+1);
    for(int i=1;i<=n;i++)
    cin>>arr[i];

    int sum=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        sum*=arr[i];
        sum+=arr[i];
        ans+=sum;
    }
   cout<<ans<<endl;
}