template<class Lazy, class Data>
struct LazySeg {
    vector<Lazy> lazy;
    vector<Data> seg;
    int SZ = 1;
    LazySeg(const int _sz) {
        while (SZ < _sz) SZ *= 2;
        seg.resize(2*SZ); lazy.resize(2*SZ);
    }
    LazySeg(const vector<Data>& _seg) {
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
        push(ind); if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) { lazy[ind] = inc; push(ind); return;}
        int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M);
        upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
    void upd(int lo, int hi, Lazy inc) { return upd(lo, hi, inc, 1, 0, SZ-1); }

    Data query(int lo, int hi, int ind, int L, int R) {
        push(ind); if (lo > R || L > hi) return Data();
        if (lo <= L && R <= hi) return seg[ind];
        int M = (L+R)/2;
        return query(lo,hi,2*ind,L,M) + query(lo,hi,2*ind+1,M+1,R);
    }
    Data query(int lo, int hi){ return query(lo, hi, 1, 0, SZ-1);}
    
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
    int mx = -1e9;
    Lazy() {}
    Lazy(int x) { mx = x; }
    Lazy& operator*=(const Lazy& a) {
        ckmax(mx, a.mx);
        return *this;
    }
};
struct Data { // data you need to store for each interval
    int mx = -1e9;
    Data() {}
    Data(int x) { mx = x; }
    friend Data operator+(const Data& a, const Data& b) {
        return Data(max(a.mx, b.mx));
    }
    Data& operator*=(const Lazy& a) {
        // sum += sz*a.add;
        ckmax(mx, a.mx);
        return *this;
    }
};
// Data A + Data B, + operation just has be associative, Data() should return identity element Data A + Data() = Data A
// if F is update applied on intervals,
// 1) need identiy update
// 2) need F(Data A + Data B) = F(Data A) + F(Data B)