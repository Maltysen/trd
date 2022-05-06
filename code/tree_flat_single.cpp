// tree flattening: half open tin/tout
ll dfs(ll u, ll p, ll t) {
    tout[u] = (tin[u]=t)+1;

    for (auto v:edges[u]) if (v!=p)
        tout[u] = dfs(v, u, tout[u]);

    return tout[u];
}
