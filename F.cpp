#ifdef LOCAL
#include "algo/dbg.hpp"
#else
#include "bits/stdc++.h"
#define dbg(...)
#endif
using namespace std;

#define int long long
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

const int inf = 1e18;
void solve(int tc = 0) {
    int n; cin >> n;
    vi a(n+2, 0);
    rep(i, 1, n+1) cin >> a[i];
    if(n == 1){
        cout << 0 << endl;
        return;
    }

    vi dp(n+3, inf); // largest min
    dp[1] = a[1];
    dp[2] = max(min(a[1], a[2]), a[1]+a[2]);
    for(int i = 3; i <= n; i++){
        dp[i] = -inf;
        ckmax(dp[i], min(dp[i-1], a[i]));
        ckmax(dp[i], min(dp[i-2], a[i] + a[i-1]));
    }

    vi dp_suff(n+3, inf);
    dp_suff[n] = a[n];
    dp_suff[n-1] = max(min(a[n], a[n-1]), a[n]+a[n-1]);
    for(int i = n-2; i >= 0; i--){
        dp_suff[i] = -inf;
        ckmax(dp_suff[i], min(dp_suff[i+1], a[i]));
        ckmax(dp_suff[i], min(dp_suff[i+2], a[i] + a[i+1]));
    }

    ll best = inf;
    // dp[0] = inf;
    // dp_suff[n+1] = inf;

    // CHECK FOR 1&2 SEPARATELY 
    
    // i = 1
    if(dp_suff[2] <= a[1]) ckmin(best, a[1] - dp_suff[2]);

    // i = 2;
    // separate
    // if(dp_suff[3] <= )

    for(int i = 2; i <= n; i++){
        dbg(i, a[i]);
        dbg(i, dp[i-1], dp_suff[i+1]);
        // just this
        if((dp[i-1] == inf or dp[i-1] <= a[i]) and (dp_suff[i+1] == inf or dp_suff[i+1] <= a[i])){
            best = min(best, a[i] - min(dp[i-1], dp_suff[i+1]));
        }

        dbg(best);
        // this and prev
        if(i >= 2){
            int s = a[i] + a[i-1];
            dbg(i, dp[i-2], dp_suff[i+1]);
            if((dp[i-2] == inf or dp[i-2] <= s) and (dp_suff[i+1] == inf or dp_suff[i+1] <= s)){
                best = min(best, s - min(dp[i-2], dp_suff[i+1]));
            }
        }
        dbg(best);
    }
    cout << best << endl;
}

signed main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
cin >> tc;
for(int t = 0; t < tc; t++) solve(t);
}