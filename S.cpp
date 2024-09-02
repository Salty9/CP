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

const int inf = 1e9;

template<class Lazy, class Info>
struct LazySeg {
    vector<Lazy> lazy;
    vector<Info> seg;
    int SZ = 1;
    LazySeg(const int _sz, Info Initial = Info()) {
        while (SZ < _sz) SZ *= 2;
        seg.assign(2*SZ, Initial); lazy.resize(2*SZ);
        for(int i = SZ-1; i >= 1; i--) pull(i);
    }
    LazySeg(const vector<Info>& _seg) {
        while (SZ < _seg.size()) SZ *= 2;
        seg.resize(2*SZ); lazy.resize(2*SZ);
        for(int i = 0; i < SZ and i < _seg.size(); i++) seg[SZ+i] = _seg[i];
        for(int i = SZ-1; i >= 1; i--) pull(i);
    }
    void push(int ind) {// modify values for current node (lazy upds floatin until pushed)
        seg[ind] *= lazy[ind];
        if (ind < SZ) rep(i,0, 2) lazy[2*ind+i] *= lazy[ind];
        lazy[ind] = Lazy();
    }
    void pull(int ind) { seg[ind] = seg[2*ind]+seg[2*ind+1]; }

    // CATION: CHOOSE PROPERLY WHETHER UPDATES SHOULD BE SET OR INCREMENTED !!!!!
    void upd(int lo, int hi, Lazy inc, int ind, int L, int R) {
        push(ind);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) { lazy[ind] = inc; push(ind); return;}
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M);
        upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
    void upd(int lo, int hi, Lazy inc) { return upd(lo, hi, inc, 1, 0, SZ-1); }

    Info query(int lo, int hi, int ind, int L, int R) {
        push(ind);
        if (lo > R || L > hi) return Info();
        if (lo <= L && R <= hi) return seg[ind];
        int M = (L+R)/2;
        return query(lo,hi,2*ind,L,M) + query(lo,hi,2*ind+1,M+1,R);
    }
    Info query(int lo, int hi){ return query(lo, hi, 1, 0, SZ-1);}

    // 0 based range and index for upd and query, root at 1, 2*ind, 2*ind + 1 children
    template<class F>
    int walk(int p, int l, int r, int x, int y, F &&pred) {
        if (l > y || r < x) return -1;
        push(p);
        if (l >= x && r <= y && !pred(seg[p])) return -1;
        if (r == l) return l;
        int m = (l + r)/ 2;
        int res = walk(2*p, l, m, x, y, pred);//find_last: flip res order(right range 1st)
        if (res == -1) res = walk(2*p + 1, m+1, r, x, y, pred);
        return res;
    }
    template<class F> int walk(int l, int r, F &&pred) { return walk(1, 0, SZ-1, l, r, pred); }
    // given 0 based inclusive range [x, y], first time pred(use lambda) is true
};
struct Lazy {
    int inc;
    Lazy(int x = 0): inc(x) {}
    Lazy& operator*=(const Lazy& a) {
        inc += a.inc;
        return *this;
    }
};
struct Info { // info you need to store for each interval
    int mx;
    Info(int x = -1e9): m {}
    friend Info operator+(const Info& a, const Info& b) {
        return Info(max(a.mx, b.mx));
    }
    Info& operator*=(const Lazy& a) {
        // sum += sz*a.add;
        ckmax(mx, a.mx);
        return *this;
    }
};
// range combiner function (Info +) has to be ASSOCIATIVE (to combine Info freely in the recursive call order)
// update combiner function (Lazy +=) has to be ASSOCIATIVE (to combine updates into one big update)
// update has to be DISTRIBUTE over range combiner function.
// upd(Info x) + upd(Info y) = upd(Info x + Info y) eg. min({l,r}+v, {L,R}+v) = min({l,r}, {L,R}) + v
// allows storing the update on both x and y, on their parent (dont have to push everything to leaf). push/distribute when needed


void solve(int tc = 0) {
    int n; cin >> n;
    vi a(n); cin >> a;
    
    int l = 0, r = n - 1;
    int lmax = -inf, rmax = -inf;
    int ans = -1;

    while(l < r){
        if(a[l++] < lmax) continue;
        if(a[r--] < rmax) continue;
        
        lmax = a[l];
        rmax = a[r];

        ckmax(ans, (a[l] + a[r])*(r-l));
    }
}

signed main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
solve();
}