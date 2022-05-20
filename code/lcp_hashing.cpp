// LCP (longest common prefix) with string hashing
ll lcp(ll i, ll j, ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return EQ(i, j, m) ? lcp(i, j, m, r) : lcp(i, j, l, m - 1);
}
