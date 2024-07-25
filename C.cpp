#include <iostream>
#include <vector>
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

// we have chains that connect to cycles
// atleast 1 cycle
void solve(int tc = 0) {
    int n, q; cin >> n >> q;
    vi a(n+1); rep(i, 1, n+1) cin >> a[i];

    vector<vi> g(n+1);
    rep(i, 1, n+1) g[a[i]].pb(i);

    auto find_start = [&](int start){
        // CYCLE WILL EXIST
        int slow = start, fast = start;

        while(true){
            slow = a[slow];
            fast = a[a[fast]];
            if(slow == fast){
                slow = start;
                while(slow != fast){
                    slow = a[slow];
                    fast = a[fast];
                }
                return slow;
            }
        }
    };

    vector<vi> cycles;
    vector<bool> is_cycle(n+1, 0);
    int start = find_start(1);
    int u = start;
    vi C;
    do{
        C.pb(u);
        is_cycle[u] = true;
        u = a[u];
    }while(u != start);
    dbg(C);
    vi chain;
    auto build_chains = [&](int u, auto&& build_chains){
        if(g[u].size() == 0){
            dbg(chain);
            return;
        }

        for(auto& v: g[u]) if(not is_cycle[v]){
            chain.pb(u);
            build_chains(v, build_chains);
            chain.pop_back();
        }
    };




    

}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
// cin >> tc;
for(int t = 0; t < tc; t++) solve(t);
}