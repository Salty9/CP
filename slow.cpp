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

vi mer(vi& a, vi& b){
    int i = 0, j = 0;
    vi ans;
    while(i < a.size() and j < b.size()){
        if(a[i] < b[j]){
            ans.pb(a[i++]);
        }else{
            ans.pb(b[j++]);
        }
    }
    while(i < a.size()) ans.pb(a[i++]);
    while(j < b.size()) ans.pb(b[j++]);
    return ans;
}

void solve(int tc = 0) {
    int n; cin >> n;
    vi a(2*n); vin(a, 2*n);

    for(int mask = 0; mask < (1 << (2*n)); mask++){
        int c = 0;
        rep(j, 0, 2*n) if(mask >> j & 1) c++;
        if(c != n) continue;

        vi ar, br;
        rep(j, 0, 2*n){
            if(mask >> j & 1) ar.pb(a[j]); 
            else br.pb(a[j]);
        }
        if(a == mer(ar, br)){
            for(auto x: ar) cout << x << " ";
            cout << endl;
            for(auto x: br) cout << x << " ";
            cout << endl << endl;
            // return;
        }
    }

    cout << -1 << endl;
    
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

for (int t = 0; t < tc; t++) solve(t);

#ifdef LOCAL_PROJECT
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
}