// Suffix array with string hashing 
ll n, suff[N];
bool lexLess(ll i, ll lI, ll j, ll lJ) {
    if(EQ(i, j, min(lI, lJ))) return lI < lJ;
    ll m = lcp(i, j, 0, min(lI, lJ) - 1);
    return s[i + m] < s[j + m];
}

    iota(suff, suff + n, 0);
    sort(suff, suff + n, [](ll i, ll j) { return lexLess(i, n - i, j, n - j); });
