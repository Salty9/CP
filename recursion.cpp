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

bool solve(int tc = 0) {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;
    
    int g = 0;
    for(auto& x: a) g = gcd(g, x);
    if((n-1)*(g-1) <= k){
        cout << (n-1)*g + k - (n-1)*(g-1) << endl;
    }else{
        int i  = k/(g-1);
    }
    return true;
}

signed main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
cin >> tc;
for(int t = 0; t < tc; t++) cout << (solve(t) ? "YES" : "NO") << endl;
}