vector<mint> invs, fac, ifac;
void init(int N) { // idempotent
    invs.resize(N), fac.resize(N), ifac.resize(N); 
    invs[1] = fac[0] = ifac[0] = 1; 
    rep(i,2,N) invs[i] = mint(-(ll)MOD/i*(int)invs[MOD%i]);
    rep(i,1,N) fac[i] = fac[i-1]*i, ifac[i] = ifac[i-1]*invs[i];
}
mint C(int a, int b) {
    if (a < b || b < 0) return 0;
    return fac[a]*ifac[b]*ifac[a-b]; 
}

// Usage: call init(10); C(6, 4); // 15