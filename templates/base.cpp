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
#define revrep(i,a,b) for (int i = a; i >= b; i--)
#define vin(a) for(auto& x: a) cin >> x;
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
template<class T> bool ckmin(T& a, T b){ return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, T b){ return b > a ? a = b, 1 : 0; }


void solve(int tc = 0) {
    $2
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
$1cin >> tc;
for(int t = 0; t < tc; t++) solve(t);
}