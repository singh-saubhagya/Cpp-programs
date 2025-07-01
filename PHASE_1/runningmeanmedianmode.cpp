

#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'


//---- Debugger ---- //
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
lli binpow(lli b,lli p,lli mod){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
//----------------- //

struct statistics {
    lli m;
    multiset<lli> a, b;
    lli sum;
    lli count;
    map<lli, lli> mode;
    multiset<pair<lli, lli>> rmode;

    void initialize() {
        sum = 0;
        m = 1e9 + 7;
        count = 0;
        a.clear();
        b.clear();
        mode.clear();
        rmode.clear();
    }

    void maintainstructure() {
        while (a.size() < b.size()) {
            auto q = b.begin();
            a.insert(*q);
            b.erase(b.begin());
        }
        while (a.size() - b.size() > 1) {
            auto q = a.rbegin();
            b.insert(*q);
            a.erase(--(a.end()));
        }
    }

    void insertion(lli k) {
        count++;
         sum =(sum + k)%m ;
        if (!a.empty() && !b.empty())
        {
            if (k > *b.begin()) 
            {
            b.insert(k);
            }
            else if (k < *a.rbegin()) 
            {
            a.insert(k);
            }
            else 
            {
            a.insert(k);
            }
             


        } else {
            a.insert(k);
            
        }

        maintainstructure();

        if (mode.find(k) != mode.end()) {
            rmode.erase({mode[k], k});
            mode[k]++;
            rmode.insert({mode[k], k});
        } else {
            mode[k]++;
            rmode.insert({mode[k], k});
        }
    }

    void deletion(lli k) {

        count--;
         sum =(sum - k)%m ;

     sum+=m;

     sum%=m;
        if (a.find(k) != a.end()) {
            a.erase(a.find(k));
        }
        else  {
            b.erase(b.find(k));
        }
       

        rmode.erase({mode[k], k});
        mode[k]--;
        if (mode[k] == 0) {
            mode.erase(k);
        } else {
            rmode.insert({mode[k], k});
        }
    }

    void findmean() {
        if (count == 0) {
            cout << -1 << endl;
            return;
        }
        lli i = binpow(count, m - 2, m);
        lli ans = (sum * i) % m;
        cout << ans << endl;
    }
    
    void findmedian() {
        if (count == 0 || (a.size()==0 && b.size()==0)) {
            cout << -1 << endl;
            return;
        }
         maintainstructure();
        if (a.size() > b.size()) {
            lli med = *a.rbegin();
            cout << med << endl;
        } else {
            lli med = ((*a.rbegin()%m  + *b.begin()%m )%m * binpow(2, m - 2, m)) % m;
            cout << med << endl;
        }
    }

   
    void findmode() {
        if (count == 0 || rmode.empty()==true) {
            cout << -1 << endl;
            return;
        }
        lli t=rmode.rbegin()->first;
        auto it = rmode.lower_bound({t, -m});
        cout<<it->second<<endl;
    }

    void solve() {
        lli q;
        initialize();
        cin >> q;
        while (q--) {
            string str;
            lli x;
            cin >> str;
            if (str == "insert") {
                cin >> x;
                insertion(x);
            } else if (str == "remove") {
                cin >> x;
                deletion(x);
            } else if (str == "getMean") {
                findmean();
            } else if (str == "getMedian") {
                findmedian();
            } else if (str == "getMode") {
                findmode();
            }
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;

    while (t--) {
        statistics random;
        random.solve();
    }
}
