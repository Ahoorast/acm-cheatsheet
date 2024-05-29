int merge(int x, int y, int l, int r) {
	int mid = l + r >> 1;
	return (x + 1LL * pw[mid - l] * y % mod) % mod;
}
int build_z(int l = 0, int r = N) {
	int id = ++sz_of_seg;
	if (l + 1 == r)  {
		cnt_z[id] = 1;
		return id;
	}
	int mid = l + r >> 1;
	L[id] = build_z(l, mid);
	R[id] = build_z(mid, r);
	cnt_z[id] = cnt_z[L[id]] + cnt_z[R[id]];
	return id;
}
int build_o(int l = 0, int r = N) {
	int id = ++sz_of_seg;
	if (l + 1 == r) {
		seg[id] = 1;
		return id;
	}
	int mid = l + r >> 1;
	L[id] = build_o(l, mid);
	R[id] = build_o(mid, r);
	seg[id] = merge(seg[L[id]], seg[R[id]], l, r);
	return id;
}
int upd(int s, int e, int v, int u, int l = 0, int r = N) { 
	int id = ++sz_of_seg;
	if (s <= l && e >= r) {
		L[id] = L[u], R[id] = R[u];
		seg[id] = seg[u], cnt_z[id] = cnt_z[u];
		return id;
	}
	int mid = l + r >> 1;
	L[id] = L[v], R[id] = R[v]; 
	if (s < mid)
		L[id] = upd(s, e, L[v], L[u], l, mid);
	if (e > mid)
		R[id] = upd(s, e, R[v], R[u], mid, r);
	seg[id] = merge(seg[L[id]], seg[R[id]], l, r);
	cnt_z[id] = cnt_z[L[id]] + cnt_z[R[id]];
	return id;
}
int find(int v, int p, int l = 0, int r = N) {
	if (p >= r || cnt_z[v] == 0)
		return -1;
	if (l + 1 == r)
		return l;
	int mid = l + r >> 1;
	int res = find(L[v], p, l, mid);
	if (res == -1)
		res = find(R[v], p, mid, r);
	return res;
}
bool compare(int v, int u, int l = 0, int r = N) {
	if (l + 1 == r) 
		return seg[v] < seg[u];
	int mid = l + r >> 1;
	if (cnt_z[R[v]] == cnt_z[R[u]] && seg[R[v]] == seg[R[u]])
		return compare(L[v], L[u], l, mid);
	return compare(R[v], R[u], mid, r);
}
