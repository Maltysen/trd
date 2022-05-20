//HLD
vl tree[N];
T val[N];
ll dep[N], idx[N], sz[N], top[N];

namespace sgtree {
    modify(i, v) is modify(idx[i], v)
    query(i, a) is query(r - a, idx[i] + 1 + N)
}

ll dfs1(ll i, ll p) {
    dep[i] = dep[p] + 1;
    sz[i] = 1;
    for(ll j : tree[i]) if(j - p)
        sz[i] += dfs1(j, i);
    sort(all(tree[i]), [](ll j, ll k) { return sz[j] > sz[k]; });
    return sz[i];
}

ll pos = 0;
void dfs2(ll i, ll p, ll t) {
    top[i] = t;
    idx[i] = pos++;
    sgtree::modify(i, val[i]);
    for(ll j : tree[i]) if(j - p)
        dfs2(j, i, t), t = i;
}

T query(ll a, ll b) {
    if(dep[a] - dep[b] == idx[a] - idx[b]) {
        if(dep[a] > dep[b]) swap(a, b);
        return sgtree::query(b, dep[b] - dep[a] + 1); //remove +1 if querying vals at edges (not vertices)
    }
    if(dep[top[a]] > dep[top[b]]) swap(a, b);
    return sgtree::f(query(a, top[b]), sgtree::query(b, dep[b] - dep[top[b]]));
}

void preproc() {
    dfs1(1, N - 1); //N - 1 is unused root vertex
    //if values initially on edges, fill val[] here
    dfs2(1, N - 1, N - 1);
}

