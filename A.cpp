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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> bool ckmin(T& a, T b){ return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, T b){ return b > a ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream&i,vector<T>&v){for(T&x:v)i>>x;return i;}

// we will never have loops 
// if we come to a node with same swap, and we find a better time
// we should search from here again

// each edge gets swapped atmost once

void solve(int tc = 0) {
    int n, m; cin >> n >> m;
    vector<vector<array<int, 3>>> g(n);

    rep(i, 0, m){
        int u, v, t; cin >> u >> v >> t;
        --u; --v;
        g[u].pb({v, t, 0}); // from -> to, weight, swaps
        g[v].pb({u, t, 1});
    }

    queue<int> q;
    vi dist(n, 1e9);
    vi mincost(n, 2e9);

    q.push(0);
    dist[0] = 0;
    mincost[0] = 0;
    while(!q.empty()){
        auto from = q.front(); q.pop();
        dbg(from);
        for(auto& [to, cost, swaps]: g[from]){
            if(mincost[from] >= cost) continue; 
            if(dist[to] >= dist[from] + swaps){
                if(cost < mincost[to]){
                    dbg(to, cost, swaps);
                    q.push(to);
                    dist[to] = dist[from] + swaps;
                    mincost[to] = cost;
                }
            }
        }
    }
    dbg(dist);
    dbg(mincost);
    cout << dist[n-1] << endl;

        
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
cin >> tc;
for(int t = 0; t < tc; t++) solve(t);
}