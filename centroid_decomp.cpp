void dfs2(int u, int p=0){
  child[u]=1;
  for(auto v: g[u]) if(v!=p and !vis[v])
    dfs2(v, u), child[u]+=child[v];
}
int getcenter(int u, int p, int n){
  for(auto v: g[u]) if(v!=p and !vis[v])
  if(child[v]>n) return getcenter(v, u, n);
  return u;
}
void decompos(int u, int p=0){
  dfs2(u);
  int c = getcenter(u, p, child[u]/2);
  vis[c] = true; /// work for c
  for(auto v : g[c]) if(!vis[v]) decompos(v, u);
}
