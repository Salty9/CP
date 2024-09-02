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
struct P{
    int x, y;
    P(int _x=-1, int _y=-1): x(_x), y(_y) {}
    // -1, -1 never occurs 
    friend ostream& operator<<(ostream &out, const P &m) {return out << "(" << m.x << ", " << m.y << ")";}
};
struct line{
    P s, e;
    line(int a, int b, int c, int d){
        s = P(a, b);
        e = P(c, d);
    }
    friend P intersect(line A, line B){
        if(A.s.x == A.e.x and B.s.x == B.e.x) return P(-1, -1); // both hor, parallel
        if(A.s.y == A.e.y and B.s.y == B.e.y) return P(-1, -1); // both vert, parallel

        if(A.s.y != A.e.y) swap(A, B);
        // A hor, B vert
        if(B.s.x < min(A.s.x, A.e.x) or max(A.s.x, A.e.x) < B.s.x) return P(-1, -1);
        if(A.s.y < min(B.s.y, B.e.y) or max(B.s.y, B.e.y) < A.s.y) return P(-1, -1);

        return P(B.s.x, A.s.y);
    }
    friend ostream& operator<<(ostream &out, const line &m) {
        return out << m.s << " -> " << m.e;
    }
};

/*
500^2 intersection, build the entire graph 
for every point keep the closest 4 intersection/edge point
*/

void solve(int tc = 0) {
    int n, t; cin >> n >> t;

    vector<line> L;

    map<int, vi> X, Y;

    rep(i, 0, n){
        int a, b, c, d; cin >> a >> b >> c >> d;
        line cur(a, b, c, d);
        for(auto& l: L){
            auto res = intersect(l, cur);
            if(res.x != -1){
                X[res.x].pb(res.y);
                Y[res.y].pb(res.x);
            }
        }
        L.pb(cur);
    }

    
}

signed main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
solve();
}