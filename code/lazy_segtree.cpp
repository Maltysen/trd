// Lazy prop segtree
// f(T, T)->T   g(D, D)->D    h(D, T)->T
namespace lazy_segtree {
	T t[2 * NN], idT;
	D d[NN], idD;
	ll n = (fill_n(d, NN, idD), NN);

    void calc(int p) {
        t[p] = f(t[p*2], t[p*2+1]);
        if (d[p]!=idD) t[p] = h(d[p], t[p]);
    }

    void apply(int p, D v) {
        t[p] = h(v, t[p]);
        if (p<n) d[p] = g(v, d[p]);
    }

    void push(int p) {
        p+=n;
        for (int s=L; s>0; --s) {
            int i=p>>s;
            if (d[i]!=idD) {
                apply(i*2, d[i]);
                apply(i*2+1, d[i]);
                d[i]=idD;
            }
        }
    }

    void modify(int p, T v) {
        push(p);
        t[p+n] = v;
        while(p > 1) calc(p /= 2);
    }

    void modify(int l, int r, D v) {
        if (v==idD) return;
        push(l), push(r-1);
        bool cl=0, cr=0;
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (cl) calc(l-1);
            if (cr) calc(r);
            if (l&1) apply(l++, v), cl=1;
            if (r&1) apply(--r, v), cr=1;
        }
        for (--l; r>0; l/=2, r/=2) {
            if (cl) calc(l);
            if (cr && (!cl || l != r)) calc(r);
        }
    }

    T query(int l, int r) {
        push(l), push(r-1);
        T resl=idT, resr=idT;
        for (l += n, r += n; l < r; l/=2, r/=2) {
            if (l&1) resl = f(resl, t[l++]);
            if (r&1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }
}

