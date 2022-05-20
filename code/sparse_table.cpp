// Sparse Table
ll rmq[N][L];

ll f(ll a, ll b) { return min(a, b); }

ll query(ll l, ll r) { //half open interval [l, r)
    ll k = 63 - __builtin_clzll(r - l);
    return f(rmq[l][k], rmq[r - (1 << k)][k]);
}

    F(j, 1, L) F(i, 0, n) {
        ll i2 = i + (1 << (j - 1));
        if(i2 < n) rmq[i][j] = f(rmq[i][j - 1], rmq[i2][j - 1]);
        else rmq[i][j] = rmq[i][j - 1];
    }
