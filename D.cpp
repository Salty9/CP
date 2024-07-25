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
#define vin(a) for(auto& x: a) cin >> x;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> bool ckmin(T& a, T b){ return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, T b){ return b > a ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream&i,vector<T>&v){for(T&x:v)i>>x;return i;}

void solve(int tc = 0) {
    int n ,a, b; cin >> n >> a >> b;
    vi p(n); cin >> p;

    const int M = 100;
    const int N = n*(n-1)/2;

    double ans = 0;

    for(int shuf = 0; shuf <= n-1; shuf++){
        for(int swp = 0; swp <= N; swp++){
            ans += (a*shuf + b*swp)*0.5;
            dbg(ans);
        }
    }
    cout << ans << endl;


}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
solve();
}