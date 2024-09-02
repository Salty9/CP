vector<int> primes, spf;

void Spf(int lim){ // lim=1e8 -> 0.8 sec.
	spf.resize(lim); // smallest prime that divides
    rep(i,2,lim) { 
        if (spf[i] == 0) spf[i] = i, primes.pb(i); 
        for (int p: primes) {
            if (p > spf[i] || i*p >= lim) break;
            spf[i*p] = p;
        }
    }
};

vector<pair<ll,ll>> factorize(ll x) { // {exp, cnt} pair in O(sqrt x) or O(log x) if spf_generated
	vector<pair<ll,ll>> res;
    if(spf.size() > 0){
        assert(x < spf.size());
        while(x > 1){
            ll p = spf[x];
            ll cnt = 0;
            while(x % p == 0) x /= p, cnt++;
            res.pb({p, cnt});
        }
        return res;
    }
	for(ll i = 2; i*i <= x; ++i) if(x % i == 0) {
		ll cnt = 0;
		while (x % i == 0) x /= i, cnt++;
		res.pb({i,cnt});
	}
	if(x > 1) res.pb({x,1});
	return res;
}

vector<ll> divisors(ll x){
    vector<ll> divs;
    for(ll i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            divs.push_back(i);
            if(i*i != x) divs.push_back(x / i);
        }
    }
    return divs;
}