#include <bits/stdc++.h>
using namespace std;

vector<int> get_nge(vector<int> arr,int n){
    vector<int> nge(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.empty())nge[i] = n;
        else nge[i] = st.top();
        st.push(i);
    }
    return nge;
}

vector<int> get_pge(vector<int> arr,int n){
    vector<int> pge(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.empty())pge[i] = -1;
        else pge[i] = st.top();
        st.push(i);
    }
    return pge;
}

int multipass_algo(vector<int> arr,int n){
    auto nge = get_nge(arr,n);
    auto pge = get_pge(arr,n);
    
    int ans = 0;
    
    for(int i=0;i<n;i++){
        if(nge[i]==n||pge[i]==-1){
            continue;        
        }
        ans += (min(arr[nge[i]],arr[pge[i]]) - arr[i]) * (nge[i]-pge[i]-1);
    }
    
    cout<<ans<<endl;
}


int get_rain_water(vector<int> arr,int n){
    stack<int> st;
    int ans = 0;
    for(int i=0;i<n;i++){// prev_greater_equal_element
        while(!st.empty() && arr[st.top()]<arr[i]){
            int del_idx = st.top();
            st.pop();
            if(!st.empty()){
                int prev_g = st.top();
                ans += (min(arr[prev_g],arr[i]) - arr[del_idx]) * (i - prev_g -1);
            }
        }    
        st.push(i);
    }
    return ans;
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    
    cout<<get_rain_water(arr,n)<<endl;
    return 0;
}