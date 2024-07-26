#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.hpp"
#else
#define dbg(...)
#endif

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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(int tc = 0) {
    int n = 7;
    string s = "";
    rep(i, 0, n) s += to_string(uid(0, 1));
    cout << s << endl;
    int q=  uid(1, 10);
    cout << q << endl;
    while(q--){
        int t = uid(1, 2);
        cout << t << " ";
        if(t == 2){
            int l = uid(1, n);
            int r = uid(l, n);
            cout << l << " " << r << endl;
        }else{
            cout << uid(1, n) << endl;
        }
    }
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
solve();
}