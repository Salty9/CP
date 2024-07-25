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
    } // recalc values for current node
    void pull(int ind) { seg[ind] = seg[2*ind]+seg[2*ind+1]; }

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
    // 0 based inclusive range for query and upd
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