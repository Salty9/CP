struct Dsu {
	vector<int> p;
	Dsu(int n) : p(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -p[find(x)]; }
	int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
	bool unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (p[a] > p[b]) swap(a, b);
		p[a] += p[b]; p[b] = a;
		return true;
	}
};