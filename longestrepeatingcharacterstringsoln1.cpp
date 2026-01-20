// class Solution {
// public:
//     bool check(string &s, int mid , int k )
//     {
//          unordered_map<char,int> freq;
//          int mf=1;
//          for(int i=0;i<mid;i++)
//          {
//             freq[s[i]]++;
//             mf=max(freq[s[i]],mf);
//          }  
//          int n=s.length();
//          for(int en=mid;en<n;en++)
//          {
//             int prev=en-mid;
//             freq[s[en]]++;
//             freq[s[prev]]--;
//             mf=max(mf,freq[s[en]]);
//          }
        
//         int ct = mid-mf;
//         if(ct<=k)
//         return true;
//         else 
//         return false ;
//     }
//     int characterReplacement(string s, int k) {
        
//         int low = 1 ; 
//         int high = s.length();
//         int ans = 1 ;
//         while(low<=high)
//         {
//             int mid = low + ((high-low)>>1);
//             if(check(s,mid,k))
//             {
//                 low=mid+1;
//                 ans=mid;
//             }
//             else 
//             {
//                 high=mid-1;
//             }
//         }
//         return ans; 
//     }
// };