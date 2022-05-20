// LCA - least common ancestor
ll dep[N], par[N][L];
vl tree[N];

void dfs(ll i, ll p) {
    dep[i] = dep[p] + 1;
    par[i][0] = p;
    F(l, 1, L) par[i][l] = par[par[i][l - 1]][l - 1];
    for(ll j : tree[i]) if(j - p) dfs(j, i);
}

ll lca(ll a, ll b) {
    if(dep[a] < dep[b]) swap(a, b);
    for(ll l = L - 1; ~l; --l) if((dep[a] - dep[b]) >> l) a = par[a][l];
    if(a == b) return a;
    for(ll l = L - 1; ~l; --l) if(par[a][l] - par[b][l]) a = par[a][l], b = par[b][l];
    return par[a][0];
}
