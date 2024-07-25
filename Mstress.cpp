#include<iostream>
#include<vector>
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

void solve(int tc = 0) {
    int n ,m , k; cin >> n >> m >> k;
    vi a(n); cin >> a;

    auto apply = [&](int y){
        ll contrib = 0;
        for(int x: a){
            dbg(x, max(x, x^y), contrib);
            contrib += max(x, x ^ y);
            dbg(x, max(x, x^y), contrib);
        }
        return contrib;
    };

    // ll best = 0;
    // int bx = 0;
    // for(int x = 0; x < (1 << m); x++){
    //     if(__builtin_popcount(x) > k) continue;
    //     ll res = apply(x);
    //     dbg(x, res);
    //     if(ckmax(best, res)){
    //         best = res;
    //         bx= x;
    //     }
    // }
    // cout << bx << endl;
    dbg(apply(12));
    
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
solve();
}