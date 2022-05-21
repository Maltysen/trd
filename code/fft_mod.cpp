@HASH
// FFT mod M
vl mult_mod(vl x, vl y) {
    int n, k;
    for (k = 0, n = 1; n < x.size() + y.size() - 1; n <<= 1, ++k);

    vector<cd> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i<x.size() ? cd(x[i]%S, x[i]/S) : cd(0,0);
        b[i] = i<y.size() ? cd(y[i]%S, y[i]/S) : cd(0,0);
    }
    fft(a), fft(b);

    for (int i=0; i<n; ++i) {
        ll j = (n-i)  & (n-1);
        c[j] = (a[i] + conj(a[j])) * b[i] / ((ld)2*n);
        d[j] = (a[i] - conj(a[j])) * b[i] / cd{0, (ld)2*n};
    }

    fft(c), fft(d);

    ll ss = S*S%M;
    vl ans(x.size()+y.size()-1);
    for (int i=0; i<n; ++i) {
        ll h0 = round(c[i].real()),
            h1 = round(c[i].imag() + d[i].real()),
            h2 = round(d[i].imag());
        ll val = (h0%M + h1%M*S%M + h2%M*ss%M)%M;
        if (i<ans.size()) ans[i]=val;
    }
    return ans;
}
