@HASH
// Fast fourier transform
typedef complex<ld> cd;

vector<cd> rt(2, 1);

void fft(vector<cd>& a) {
    int n = a.size();
    vector<int> rev(n);
    for (int i=0; i<n; ++i)
        if(i < (rev[i] = (rev[i / 2] | (i & 1 ? n : 0)) / 2)) swap(a[i], a[rev[i]]);
    for(int k = 1; k < n; k *= 2)
        for(int i = 0; i < n; i += 2 * k) F(j, 0, k) {
            cd z = rt[j + k] * a[i + j + k];
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

vector<ld> mult(vector<ld> a, vector<ld> b) {
    int n = a.size() + b.size() - 1;
    while(__builtin_popcount(n) > 1) n++;
    vector<cd> in(n), out(n);
    a.resize(n), b.resize(n);
    for (int i=0; i<n; ++i) in[i] = {a[i], b[i]};
    fft(in);
    for(cd& x : in) x *= x;
    for (int i=0; i<n; ++i) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    vector<ld> res(n);
    for (int i=0; i<n; ++i) res[i] = out[i].imag() / 4 / n;
    return res;
}

    for(int k = 2; k < (1 << L); k *= 2) {
        cd x = polar(1.l, acos(-1.l) / k);
        for (int i=k; i<2*k; ++i) rt.push_back(rt[i / 2] * (i & 1 ? x : 1));
    }
