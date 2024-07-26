#include <bits/stdc++.h>
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

void solve(int tc = 0) {
    string s; cin >> s;
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        if(k == 1){
            int x; cin >>  x;
            --x;
            s[x] = (s[x] == '1' ? '0' : '1');
        }else{
            int l, r; cin >> l >> r;
            --l, --r;
            string t = s.substr(l, r-l+1);
            while(t.find("01") != string::npos){
                t.erase(t.find("01"), 2);
            }
            cout << t.size() << endl;
        }
    }
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int tc = 1;
// cin >> tc;
for(int t = 0; t < tc; t++) solve(t);
}