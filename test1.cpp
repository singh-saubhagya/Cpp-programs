#include<bits/stdc++.h>
using namespace std;
    typedef long long lli;
    vector<lli> a;
    
    void findrepre(lli n, vector<lli>& temp) {
        if (n == 0) {
            temp.push_back(0);
            return;
        }
        while (n != 0) {
            lli rem = n % 2;
            temp.push_back(rem);
            n = n >> 1;
        }
        reverse(temp.begin(), temp.end());
    }
    
    bool checkvalid(vector<lli>& digit, lli hf, lli n) {
        lli len = a.size();
        vector<lli> num;
        
        // Add first half
        for (lli i = 0; i <= hf; i++) {
            num.push_back(digit[i]);
        }
        
        // Add second half (mirror of first half)
        lli start = hf;
        if (len & 1) {  // If odd length, skip middle digit
            start--;
        }
        for (lli i = start; i >= 0; i--) {
            num.push_back(digit[i]);
        }
        
        // Convert to decimal
        lli cal = 0;
        lli pw = 1;
        for (lli i = num.size() - 1; i >= 0; i--) {
            cal = cal + pw * num[i];
            pw = pw * 2;
        }
        
        return cal <= n;
    }
    
    lli rec(lli level, lli tlevel, vector<lli>& digit, lli tight, lli n) {
        if (level == tlevel + 1) {
            return checkvalid(digit, tlevel, n);
        }
        
        lli limit = tight ? a[level] : 1;
        lli ans = 0;
        
        for (lli i = 0; i <= limit; i++) {
            lli newtight = tight && (i == a[level]);  // Fixed: compare i with a[level]
            digit.push_back(i);
            ans += rec(level + 1, tlevel, digit, newtight, n);
            digit.pop_back();
        }
        return ans;
    }
    
    int countBinaryPalindromes(long long n) {
        if (n == 0) return 1;  // Edge case
        
        a.clear();
        findrepre(n, a);
        lli len = a.size();
        
        lli total = 0;
        
        // Count palindromes of length < len
        for (lli i = 1; i < len; i++) {
            if (i == 1) {
                total += 2;  // "0" and "1"
            } else {
                lli hf = (i + 1) / 2 - 1;  // Number of free positions in first half (excluding leading 1)
                total += (1LL << hf);  // 2^hf palindromes
            }
        }
        
        // Count palindromes of length = len using digit DP
        if (len == 1) {
            // For single digit, count 0 to min(n, 1)
            total = min(n + 1, 2LL);
        } else {
            lli hf = (len + 1) / 2 - 1;  // Half length excluding the leading 1
            vector<lli> digit;
            digit.push_back(1);  // Leading bit is always 1 for multi-digit numbers
            total += rec(1, hf, digit, 1, n);
        }
        
        return total;
    }

        signed main()
        {
          cin.tie(0); cout.tie(0);
           
          lli n;
          cin>>n;
          cout<<countBinaryPalindromes(n);
        }