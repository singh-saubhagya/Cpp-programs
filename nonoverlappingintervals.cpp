// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end());
//         vector<vector<int>> inter;
//         inter.push_back(intervals[0]);
//         int n=intervals.size();
//         for(int i=1;i<n;i++)
//         {
//             if(inter.back()[1]>intervals[i][0])
//             {
//                 if(inter.back()[1]<intervals[i][1])
//                 {
//                     // keep this interval
//                 }
//                 else 
//                 {
//                     inter.pop_back();
//                     inter.push_back(intervals[i]);
//                 }
//             }
//             else 
//             {
//                 inter.push_back(intervals[i]);
//             }
//         }
//         return n-inter.size();
//     }
// };