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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(int tc = 0) {
    int n = uid(3, 1e5);
    int m = uid(1, 100);
    cout << n << " " << m << endl;
    rep(i, 0, m){
        int x = uid(1, n/2);
        int y = uid(x+1, n);
        cout << x << " " << y << endl;
    }
    
}

signed main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
//cin >> tc;
for(int t = 0; t < tc; t++) solve(t);
}