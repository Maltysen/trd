// Tree flat for path querys from ancestor to child
vl graph[N];
ll idx = 0, a[2 * N], tin[N], tout[N];

void dfs(ll u, ll p) {
    tin[u] = tout[u] = idx;
    a[idx++] = u;
    for(ll v : graph[u]) if(v - p) dfs(v, u);
    tout[u] = idx;
    a[idx++] = u;
}
