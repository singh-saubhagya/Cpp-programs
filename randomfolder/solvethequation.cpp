#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

lli binpow(lli b, lli p, lli mod) {
    lli ans = 1;
    b %= mod;
    for(; p; p >>= 1) {
        if(p & 1) ans = ans * b % mod;
        b = b * b % mod;
    }
    return ans;
}

lli operation(lli a, lli b, char opr, lli n) {
    lli result;
    if(opr == '/') {
        // Perform division using multiplicative inverse
        result = a * binpow(b, n - 2, n) % n;
        return result;
    } else {
        a = a % n;
        b = b % n;
        switch(opr) {
            case '*': result = a * b; break;
            case '+': result = (a + b); break;
            case '-': result = a - b; break;
            default: return 1;
        }
        result = (result % n + n) % n;
        return result;
    }
}

lli priority(char ch) {
    if(ch == '/') return 4;
    else if(ch == '*') return 3;
    else if(ch == '+'|| ch=='-') return 2;
    else return 1;
}

lli solve(string str) {
    vector<lli> v;
    lli l = str.length();
    vector<char> arr; 
    lli flag = 1;
    string temp;
    lli size = 0;

    for(lli i = 0; i < l; i++) {
        char ch = str[i];
        if(ch >= '0' && ch <= '9') {
            temp.push_back(ch);
            if(i == l - 1 || str[i + 1] < '0' || str[i + 1] > '9') {
                lli n = stoi(temp);
                v.push_back(n);
                temp.resize(0);
            }
        } else if(ch == '/' || ch == '*' || ch == '+' || ch == '-') {
            size++;
            arr.push_back(ch);
            if(size > 1) {
                if(priority(arr[1]) > priority(arr[0])) {
                    flag = 2;
                } else { 
                    flag = 1;
                }
            }
        }
    }

    lli result;
    lli n = v[3];
    if(n==1)
    return 0;
    if(flag == 1) {
        result = operation(v[0], v[1], arr[0], n);
        result = operation(result, v[2], arr[1], n);
    } else {
        result = operation(v[1], v[2], arr[1], n);
        result = operation(v[0], result, arr[0], n);
    }

    result = result % n;
    result = (result + n) % n;
    return result;
}

int main() {
    lli q;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

     cin >> q;
     cin.ignore();
      

    vector<lli> x;
    while(q--) {
        string str;
        getline(cin, str);
        lli result = solve(str);
        x.push_back(result);
       
    }


    for(lli i : x) {
        cout << i << endl;
    }
 
}
