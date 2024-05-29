int add(int a, int b) {
	a += b;
	a += (a < 0) * mod - (a >= mod) * mod;
	return a;
}
 
int mul(int a, int b) {
	return 1LL * a * b % mod;
}
 
struct mat {
	int n, m;
	vector<vector<int>> a;
	mat(int x = 0, int y = 0) {
		n = x, m = y;
		a.resize(n, vector<int>(m, 0));
	}
	void identity() {
		assert(n == m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = i == j;
	}
	void clear() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = 0;
	}
	void resize(int x, int y) {
		n = x, m = y;
		a.resize(n, vector<int>(m, 0));
	}
	mat operator * (const mat &b) {
		assert(m == b.n);
		mat res(n, b.m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < b.m; j++)
				for (int k = 0; k < m; k++)
					res.a[i][j] = add(res.a[i][j], mul(a[i][k], b.a[k][j]));
		return res;
	}
	void operator *= (const mat &b) {
		*this = *this * b;
	}
	mat operator ^ (long long b) {
		mat res(n, m), add = *this;
		for (res.identity(); b; b >>= 1, add *= add)
			if (b & 1)
				res *= add;
		return res;
	}
	void operator ^= (long long b) {
		*this = *this ^ b;
	}
};
