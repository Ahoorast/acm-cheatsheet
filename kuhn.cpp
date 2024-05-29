bool dfs(int v) {
	vis[v] = true;
	for (auto u: adj[v])
		if (mt[u] == -1 || (!vis[mt[u]] && dfs(mt[u]))) {
			mt[v] = u, mt[u] = v;
			return true;
		}
	return false;
}
bool fnd = true;
while (fnd) {
	fnd = false;
	fill(vis, vis + N, false);
	for (int i = 0; i < n; i++)
		if (mt[i] == -1 && !vis[i] && dfs(i)) 
			fnd = true, res++;
}
return res == n;

