int add(string &s){
	int cur=0;
	for(char c:s){
		if(!nxt[c-'a'][cur])
			nxt[c-'a'][cur]=++cnt;
		cur=nxt[c-'a'][cur];
	}
	return cur;
}
void aho(){
	int s=0,e=0;
	for(int i=0;i<26;i++)
		if(nxt[i][0])
			d[e++]=nxt[i][0];
	while(s<e){
		int v=d[s++];
		adj[f[v]].pb(v);
		for(int i=0;i<26;i++){
			if(nxt[i][v]){
				f[nxt[i][v]]=nxt[i][f[v]];
				d[e++]=nxt[i][v];
			}
			else
				nxt[i][v]=nxt[i][f[v]];
		}
	}
}
