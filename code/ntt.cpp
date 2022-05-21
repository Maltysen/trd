@HASH
// NTT (Number theoretic transform)
// M = 998244353
ll root = 62;
vl rt(2, 1);

void ntt(vl &a) {
	ll n = a.size();
	vl rev(n);
	F(i, 0, n) if(i < (rev[i] = (rev[i / 2] | (i & 1 ? n : 0)) / 2)) swap(a[i], a[rev[i]]);
	for(ll k = 1; k < n; k *= 2)
		for(ll i = 0; i < n; i += 2 * k) F(j, 0, k) {
			ll z = rt[j + k] * a[i + j + k] % M, &ai = a[i + j];
			a[i + j + k] = (ai - z + M) % M;
			ai = (ai + z) % M;
		}
}

vl mult(vl a, vl b) {
	ll n = a.size() + b.size();
    while(__builtin_popcountll(n) > 1) n++;
    a.resize(n), b.resize(n);
    vl out(n); ll in = inv(n);
	ntt(a), ntt(b);
	F(i, 0, n) out[-i & (n - 1)] = a[i] * b[i] % M * in % M;
	ntt(out);
	return out;
}

    F(s, 2, L) {
		ll z[] = {1, pw(root, M >> s)};
		F(i, 1 << (s - 1), 1 << s) rt.push_back(rt[i / 2] * z[i & 1] % M);
	}
