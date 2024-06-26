template<int MOD, int RT> struct Mint {
	static const int mod = MOD;
	static constexpr Mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	Mint():v(0) {}
	Mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const Mint& o) const {
		return v == o.v; }
	friend bool operator!=(const Mint& a, const Mint& b) { 
		return !(a == b); }
	friend bool operator<(const Mint& a, const Mint& b) { 
		return a.v < b.v; }
	// friend void re(Mint& a) { ll x; re(x); a = Mint(x); }
	// friend str ts(Mint a) { return ts(a.v); }
    
	Mint& operator+=(const Mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	Mint& operator-=(const mint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	Mint& operator*=(const Mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	Mint& operator/=(const Mint& o) { return (*this) *= inv(o); }
	friend Mint pow(Mint a, ll p) {
		Mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend Mint inv(const Mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	Mint operator-() const { return mint(-v); }
	Mint& operator++() { return *this += 1; }
	Mint& operator--() { return *this -= 1; }
	friend Mint operator+(Mint a, const Mint& b) { return a += b; }
	friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
	friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
	friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
};
const int MOD = (int)1e9 + 7; // change accoridngly
using mint = Mint<MOD,5>;