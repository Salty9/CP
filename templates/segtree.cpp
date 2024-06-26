template<class T> struct Segtree {
   // initialize ID if need nonzero & define cmb so that cmb(ID,b) = b
    const T ID{};
    T cmb(T a, T b) {
        return a+b; 
    } 
    int n; vector<T> seg;
    Segtree(int sz){ init(sz); } // just call init if i pass in size 
    Segtree(){} // nothing if i dont pass stuff
    void init(int _n) { // upd, query also work if n = _n
        for (n = 1; n < _n; ) n *= 2; 
        seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) {  // set val at position p [0 idx]
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {    // zero-indexed, inclusive
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = cmb(ra,seg[l++]);
            if (r&1) rb = cmb(seg[--r],rb);
        }
        return cmb(ra,rb);
    }
    /// int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range
    ///     if (r < lo || val > seg[ind]) return -1;
    ///     if (l == r) return l;
    ///     int m = (l+r)/2;
    ///     int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
    ///     return first_at_least(lo,val,2*ind+1,m+1,r);
    /// }
};
// usage: Segtree<int> seg; seg.init(n); if you want to init later
// OR Segtree<int> seg(n);