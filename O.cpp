#ifdef LOCAL
#include "algo/dbg.hpp"
#else
#include "bits/stdc++.h"
#define dbg(...)
#endif
using namespace std;

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

template<int MOD, int RT> struct Mint {
    static const int mod = MOD;
    static constexpr Mint rt() { return RT; } // primitive root for FFT
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    Mint():v(0) {}
    Mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }

    bool operator==(const Mint& o) const { return v == o.v; }
    friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
    friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }

    Mint& operator+=(const Mint& o) { if ((v += o.v) >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint& o) { if ((v -= o.v) < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint& o) { v = int((ll)v*o.v%MOD); return *this; }
    Mint& operator/=(const Mint& o) { return (*this) *= inv(o); }
    friend Mint pow(Mint a, ll p) {
        Mint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a; return ans; }
    friend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a,MOD-2); }

    Mint operator-() const { return Mint(-v); }
    Mint& operator++() { return *this += 1; }
    Mint& operator--() { return *this -= 1; }
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
    friend ostream& operator<<(ostream &out, const Mint &m) {return out << m.v;}
    friend istream& operator>>(istream &in, Mint &m) {long long x; in >> x; m = Mint(x); return in;}
};

const int MOD = 1e9 + 7;
using mint = Mint<MOD,5>;

void solve(int tc = 0) {
    int n, m; cin >> n >> m;
    vector<vi> A(n+1, vi(m+1)), B(n+1, vi(m+1));
    rep(i, 1, n+1) rep(j, 1, m+1) cin >> A[i][j];
    rep(i, 1, n+1) rep(j, 1, m+1) cin >> B[i][j];

    mint p = uid(2, MOD-1), q;
    do{
        q = uid(2, MOD-1);
    }while(p == q);

    vector<vector<mint>> H(n+1, vector<mint>(m+1, 0));
    vector<vector<mint>> H2(n+1, vector<mint>(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            H[i][j] = H[i-1][j]*q + H[i][j-1]*p  - H[i-1][j-1]*p*q + A[i][j];
            H2[i][j] = H2[i-1][j]*q + H2[i][j-1]*p  - H2[i-1][j-1]*p*q + B[i][j];
        }
    }
    vector<mint> powp(max(n,m)+1, 1);
    vector<mint> powq(max(n,m)+1, 1);
    rep(i, 0, max(n, m)){
        powp[i+1] = powp[i]*p;
        powq[i+1] = powq[i]*q;
    }
    auto hash = [&](int a, int b, int x, int y) -> mint{
        return (H[x][y] - H[a-1][y]*powq[x-a+1] - H[x][b-1]*powp[y-b+1] + H[a-1][b-1]*powq[x-a+1]*powp[y-b+1]); // p, q order sus 
    };
    auto hash2 = [&](int a, int b, int x, int y) -> mint{
        return (H2[x][y] - H2[a-1][y]*powq[x-a+1] - H2[x][b-1]*powp[y-b+1] + H2[a-1][b-1]*powq[x-a+1]*powp[y-b+1]); // p, q order sus 
    };

    vector<pii> pos(m*n+1);
    rep(i, 1, n+1) rep(j, 1, m+1) pos[B[i][j]] = {i, j};

    vector<vi> h(n+1, vi(m+1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int wl = 1, wh = m+1;
            while(wh > wl+1){
                int mid = (wl + wh)/2;
                auto& [x, y] = pos[A[i][j]];
                if(j+mid <= m+1 and y + mid <= m+1 and hash(i, j, i, j+mid-1) == hash2(x, y, x, y+mid-1)) wl = mid;
                else wh = mid;
            }
            h[i][j] = wl;
        }
    }

    int best = 1;
    for(int L = 1; L <= m; L++){
        // largest histogram, gfg code
        stack<int> st;
        int i = 1;
        while(i <= n){
            if(st.empty() || h[st.top()][L] <= h[i][L]){
                st.push(i++);
            }else{
                int t = st.top(); st.pop();
                ckmax(best, h[t][L]*(st.empty() ? i-1 : i - st.top() - 2));
            }
        }
        while (!st.empty()){
            int t = st.top(); st.pop();
            ckmax(best, h[t][L] * (st.empty() ? i-1 : i - st.top() - 2));
        }
        dbg(L, best);
    }
    cout << best << endl;
}

signed main() {    
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
solve();
}