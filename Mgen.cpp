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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> bool ckmin(T& a, T b){ return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, T b){ return b > a ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream&i,vector<T>&v){for(T&x:v)i>>x;return i;}

void solve(int tc = 0) {
    int n = uid(1, 20);
    int m = uid(1, 5);
    int k = uid(0, m);

    cout << n << " " << m << " " << k << endl;
    rep(_, 0, n){
        cout << uid(0, (1  << m) - 1)  << " ";
    }
    cout << endl;

    
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
solve();
}