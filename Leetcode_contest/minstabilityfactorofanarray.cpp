#include<bits/stdc++.h>
using namespace std;
 int  findgcd(int a,int b)
    {
    if(a==0)
    return b;
    return findgcd(b%a,a);
    }
   
    bool check(int mid , vector<int> &nums, int maxC)// is there exist a subarray of size atleast mid , such that gcd of it is >=2;, after making minimum no of  operations.
    {
        int n=nums.size();
        int ct=0;// no of operations needed to make the subarray's gcd =1
        for(int i=0;i<=n-mid;)
        {
           long long val=nums[i];
            int j;
            for(j=i;j<=mid-1+i;j++)
            {
                val=findgcd(val,nums[j]);
                if(val==1)
                {
                    break;
                }
            }
            if(val>=2)
            {
                ct++;// 1 operation needed and that operation will be inserting prime in the mid-1+i, pn , such that  subarray starting with x where x belong to range i to i+mid-1, has gcd = 1 .
                if(ct>maxC)
                break;
                i=i+mid;
            }
            else 
            {
                i++;// gcd is 1 , for subarray startin with i of leng mid, so moving to next subarray staring with i+1, 
            }
        }
        if(ct>maxC)
        return true;

        else return false;
    }
    int minStable(vector<int>& nums, int maxC) {


        int low=1;
        int high=nums.size();
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,nums,maxC))
            {
                low=mid+1;
                ans=mid;
            }
            else 
            high=mid-1;
        }
       return ans;
        
    }

    signed main()
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr;
        arr.resize(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
       cout<<minStable(arr,k);

    }