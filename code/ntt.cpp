@HASH
// NTT (Number theoretic transform)
// M = 998244353
ll root = 62;
vl rt(2, 1);

void ntt(vl &a) {
	int n = a.size();
	vector<int> rev(n);
	for (int i=0; i<n; ++i)
        if(i < (rev[i] = (rev[i / 2] | (i & 1 ? n : 0)) / 2)) swap(a[i], a[rev[i]]);
	for(int k = 1; k < n; k *= 2)
		for(int i = 0; i < n; i += 2 * k) F(j, 0, k) {
			ll z = rt[j + k] * a[i + j + k] % M, &ai = a[i + j];
			a[i + j + k] = (ai - z + M) % M;
			ai = (ai + z) % M;
		}
}

vl mult(vl a, vl b) {
	int n = a.size() + b.size() - 1;
    while(__builtin_popcount(n) > 1) n++;
    a.resize(n), b.resize(n);
    vl out(n); ll in = inv(n);
	ntt(a), ntt(b);
	for (int i=0; i<n; ++i) out[-i & (n - 1)] = a[i] * b[i] % M * in % M;
	ntt(out);
	return out;
}

    F(s, 2, L) {
		ll z[] = {1, pw(root, M >> s)};
		for(int i=1 << (s - 1); i<(1 << s); ++i)
            rt.push_back(rt[i / 2] * z[i & 1] % M);
	}
