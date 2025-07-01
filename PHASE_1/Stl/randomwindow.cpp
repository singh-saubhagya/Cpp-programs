#include <bits/stdc++.h>
using namespace std;

struct bag{
    int leftsum,rightsum;
    multiset<int> leftvals,rightvals;
    
    void init(){
        leftsum = 0,rightsum=0;
        leftvals.clear(); rightvals.clear();
    }
    int get_median(){
        if(leftvals.size()==0)return -1;
        return *leftvals.rbegin();
    }
    void rebalance(){
        while(rightvals.size()>leftvals.size()){
            int x = *rightvals.begin();
            rightvals.erase(rightvals.find(x));
            rightsum -= x;
            
            leftvals.insert(x);
            leftsum += x;
        }
        
        while(leftvals.size()-rightvals.size()>=2){
            int x = *leftvals.rbegin();
            leftvals.erase(leftvals.find(x));
            leftsum -= x;
            
            rightvals.insert(x);
            rightsum += x;
        }
    }
    
    void insert(int x){
        if(x<=get_median()){
            leftvals.insert(x);
            leftsum+=x;
        }else{
            rightvals.insert(x);
            rightsum+=x;
        }
        rebalance();
    }
    void erase(int x){
        if(x<=get_median()){
            leftvals.erase(leftvals.find(x));
            leftsum-=x;
        }else{
            rightvals.erase(rightvals.find(x));
            rightsum-=x;
        }
        rebalance();
    }
    int get_min_cost(){
        int median = get_median();
        int leftcost = leftvals.size()*median-leftsum;
        int rightcost = rightsum - rightvals.size()*median;
        return leftcost + rightcost;
    }
};

signed main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    bag ds;
    ds.init();
    
    for(int i=0;i<n;i++){
        // [i-k+1,....,i]
        // insert index i,
        ds.insert(arr[i]);
        // remove index i-k if it exists
        if(i-k>=0) ds.erase(arr[i-k]);
        // if valid, 
        if(i>=k-1){
            // you have a k length subarray, use the datastructure
            cout<<ds.get_min_cost()<<endl;
        }
    }
}