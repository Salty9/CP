#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PROJECT
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rrep(i,a,b) for (int i = a; i >= b; i--)

#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> bool ckmin(T& a, T b){ return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, T b){ return b > a ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream&i,vector<T>&v){for(T&x:v)i>>x;return i;}

// first bit is tokubetsu
// afterwards, every 0 in x does nothing
// every 1.

void solve(int tc = 0) {
    int n ,m , k; cin >> n >> m >> k;
    vi a(n); cin >> a;

    vector<pair<ll, ll>> sor;
    for(int i = m-1; i >= 0; i--){
        ll con = 0;
        for(ll& x: a) if((x >> i & 1) == 0) con += (1 << i);
        sor.pb({-con, i});
    }
    sort(all(sor));
    dbg(sor);
    
    int x = 0;
    rep(i, 0, k){
        if(sor[i].first == 0) break;
        x ^= (1 << sor[i].second);
    }
    cout << x << endl;

}

signed main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
// cin >> tc;
for(int t = 0; t < tc; t++) solve(t);
}