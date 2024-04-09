// Fast Bitwise Convolution
void FST(vl& a, bool in) {
	for (int n = a.size(), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) for(int j=i; j<i+step; ++j) {
			ll &u = a[j], &v = a[j + step];
            ll ou=u, ov=v;
            u = (ou+ov)%M, v=(ou-ov+M)%M; // XOR
            if (inv) u=(ov-ou+M)%M, v=ou; else u=ov, v=(ou+ov)%M; // AND
            if (inv) u=ov, v=(ou-ov+M)%M; else u=(ou+ov)%M, v=ou; // OR
		}
	}
    ll as = inv(a.size());
	if (in) for (ll& x : a) ( x *= as )%=M; // XOR only
}

