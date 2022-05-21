typedef complex<ld> cd;

vector<cd> rt(2, 1);

void fft(vector<cd>& a) {
    ll n = a.size();
    vector<ll> rev(n);
    F(i, 0, n) if(i < (rev[i] = (rev[i / 2] | (i & 1 ? n : 0)) / 2)) swap(a[i], a[rev[i]]);
    for(ll k = 1; k < n; k *= 2)
        for(ll i = 0; i < n; i += 2 * k) F(j, 0, k) {
            cd z = rt[j + k] * a[i + j + k];
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

vector<ld> mult(vector<ld> a, vector<ld> b) {
    ll n = a.size() + b.size();
    while(__builtin_popcountll(n) > 1) n++;
    vector<cd> in(n), out(n);
    a.resize(n), b.resize(n);
    F(i, 0, n) in[i] = {a[i], b[i]};
    fft(in);
    for(cd& x : in) x *= x;
    F(i, 0, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    vector<ld> res(n);
    F(i, 0, n) res[i] = out[i].imag() / 4 / n;
    return res;
}

    for(ll k = 2; k < (1 << L); k *= 2) {
        cd x = polar(1.l, acos(-1.l) / k);
        F(i, k, 2 * k) rt.push_back(rt[i / 2] * (i & 1 ? x : 1));
    }
