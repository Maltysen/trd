// Deltas for suffix tree without map
int to[NN][27], lk[NN][27];	
int lf[NN], rt[NN], par[NN], path[NN];	
ll BAD = INT_MIN;

    for (v=o; lk[v][s[i]]==BAD && v; v=par[v])

    ll w = lk[v][s[i]]==BAD ? 1 : lk[v][s[i]]+1;
    if (to[w][s[V]]!=BAD) {

    for (auto &c:s) c-='a', c++;
    for (ll i=0; i<NN; ++i) {
            fill(all(to[i]), BAD);
            fill(all(lk[i]), BAD);
    }
