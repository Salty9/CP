#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

#ifdef LOCAL_PROJECT
    #include "debug.hpp"
#else
    #define dbg(...)
#endif

#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define vin(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
template<class T> bool ckmin(T& a, T b){ return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, T b){ return b > a ? a = b, 1 : 0; }

void solve(int tc = 0) {
    int n; cin >> n;
    string s; cin >> s;
    if(n == 2){
        cout << s << endl;
        return;
    }

    ll best = 1e16;
    for(int m = 0; m < (1 << (n - 2)); m++){
        vll a;
        rep(i, 0, n) a.pb(s[i] - '0');

        rep(j, 0, n-2){
            if(m >> j & 1){
                a[j+1] *= a[j];
                if(a[j+1] > 180) goto nxt;
                a[j] = 0;
            }
        }
        
        ckmin(best, accumulate(all(a), 0LL));
        nxt:;
    }
    cout << best << endl;

}

int main() {

#ifdef LOCAL_PROJECT
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("input","r",stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#endif

ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
cin >> tc;

for (int t = 0; t < tc; t++) solve(t);

#ifdef LOCAL_PROJECT
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
}