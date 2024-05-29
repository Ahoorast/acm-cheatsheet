void euler(int v) {
	while (adj[v].size()) {
		int u = adj[v].back();
		adj[v].pop_back();
		euler(u);
	}
	L.push_back(v);
}

for (int i = 0; i < N; i++)
		if ((cnt == 0 || (in_deg[i] < out_deg[i])) && adj[i].size()) {
			euler(i);
			break;
		}

