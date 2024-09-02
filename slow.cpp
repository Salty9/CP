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
    int n, m; cin >> n >> m;
    vector<vi> g(n+1);
    vector<pii> eds;

    rep(i, 0, m){
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        eds.pb({a, b});
    }

    vector<int> color(n+1, -1);
    auto dfs = [&](int u, int c, auto&& dfs) -> void{
        if(color[u] == (c^1)){
            cout << -1 << endl; exit(0);
        }
        if(color[u] == c) return;

        color[u] = c;
        for(auto& v: g[u]) dfs(v, c^1, dfs);
    };
    for(int i = 1; i <= n; i++) if(color[i] == -1) dfs(i, 0, dfs);
    
}

signed main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
//cin >> tc;
for(int t = 0; t < tc; t++) solve(t);
}