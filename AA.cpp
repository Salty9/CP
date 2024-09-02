#ifdef LOCAL
#include "algo/dbg.hpp"
#else
#include "bits/stdc++.h"
#define dbg(...)
#endif
using namespace std;

#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define rrep(i,a,b) for (int i = (a); i >= (b); --i)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> bool ckmin(T& a, T b){ return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, T b){ return b > a ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream&i,vector<T>&v){for(T&x:v)i>>x;return i;}

void solve(int tc = 0) {
    string a; cin >> a;
    int n = a.size();

    string Q; cin >> Q;
    int m = Q.size();

    int l = 0, r = 0;
    vi sz;
    while(l < n and r < n){
        while(a[r] == '.') r++;
        if(r-l >= 2) sz.pb(r-l);
        r++;
        l = r;
    }
    dbg(sz);
    int Val = accumulate(all(sz), 0) - 2*sz.size() + count(all(sz), 2);
    int Min = (sz.empty() ? 0 : *min_element(all(sz)));

    auto blocked = [&](int take) -> bool{
        int M = 0, C = 0;
        for(int i = 0; i < take; i++){
            if(Q[i] == 'C') C++;
            else M++;
        }
        dbg(M, C, Val, Min);
        return (2*M + 3*C >= Val) || (Min < 2);
    };

    // int L = -1, R = m+1;
    // while(R > L+1){
    //     int mid = (L+R)/2;
    //     blocked(mid) ? R = mid: L = mid;
    // }
    // dbg(L, R);
    // for(int i = 0; i < R; i++) cout << "Y";
    // for(int i = R; i <= m; i++) cout << "N";
    // cout << endl;

    dbg(blocked(2));
    
    
    

    
}

signed main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
cin >> tc;
for(int t = 0; t < tc; t++) solve(t);
}