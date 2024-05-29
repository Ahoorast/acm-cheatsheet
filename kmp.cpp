vector<bool> kmp(string s, string t) {
	int n = (int)(s.size()), m = (int)(t.size());
	vector<int> nxt(m, 0);
	vector<bool> res(n, 0);
	for (int i = 1, len = 0; i < m; i++) {
		while (len && t[len] != t[i])
			len = nxt[len - 1];
		len += t[len] == t[i];
		nxt[i] = len;
	}
	for (int i = 0, j = 0; i < n; i++) {
		while (j && s[i] != t[j])
			j = nxt[j - 1];
		j += s[i] == t[j];
		if (j)
			res[i - j + 1] = j == m;
		if (j == m)
			j = nxt[j - 1];
	}
	return res;
}

