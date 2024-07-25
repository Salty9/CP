struct Dsu {
	vector<int> p;
	Dsu(int n) : p(n, -1) {}
	bool sameSet(int a, int b) { return parent(a) == parent(b); }
	int size(int x) { return -p[parent(x)]; }
	int parent(int x) { return p[x] < 0 ? x : p[x] = parent(p[x]); }
	bool unite(int a, int b) {
		a = parent(a), b = parent(b);
		if (a == b) return false;
		if (p[a] > p[b]) swap(a, b);
		p[a] += p[b]; p[b] = a;
		return true;
	}
};
