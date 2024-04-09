@HASH
//Mergesort Tree
    ll f(ll i, ll k)
        return (ll)(lower_bound(all(t[i]), k) - t[i].begin());

    void build() { //call after setting t[i + N] for i in [0, n)
        for(ll i = N - 1; i; --i) merge(all(t[2 * i]), all(t[2 * i + 1]), back_inserter(t[i]));

    ll query(ll l, ll r, ll k) if(l & 1) res += f(l++, k);
