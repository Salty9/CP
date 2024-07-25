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

void solve(int tc = 0) {
    int n; cin >> n;
    int B = 0;
    for(int i = 1; i <= n; i++) B += (i+1)/2;
    cout << B << endl;

    char F[2] = {'0', '1'};
    vi nums;
    int best = 0;

    for(int i = 0; i < (1 << n); i++){
        int ans = 0;
        for(int j = 0; j < n; j++){
            int c = 0;
            for(int k = j; k < n; k++){
                if(i >> k & 1) c++;
                if(c & 1) ans++;
            }
        }
        if(ckmax(best, ans)){
            nums.clear();
            nums.pb(i);
        }else if(best == ans){
            nums.pb(i);
        }
        if(nums.size() > 100){
            dbg(i);
            break;
        }

    }
    for(auto x: nums) dbg(bitset<16>(x));
    dbg(best, nums.size());
    
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
solve();
}