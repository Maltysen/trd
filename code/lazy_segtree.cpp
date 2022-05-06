// Lazy prop segtree
struct lazy_segtree {
	T t[2 * NN], idT;
	D d[NN], idD;
	ll n = NN;

    void calc(int p) {
        t[p] = f(t[p*2], t[p*2+1]);
        if (d[p]!=idD) t[p] = h(d[p], t[p]);
    }

    void apply(int p, D v) {
        t[p] = h(v, t[p]);
        if (p<n) d[p] = g(v, d[p]);
    }

    void build(int l, int r) {
        for (l+=n, r+=n-1; l>1; ) {
            l/=2, r/=2;
            for (int i=r; i>=l; --i) calc(i);
        }
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
        build(p, p+1);
    }

    void modify(int l, int r, D v) {
        if (v==idD) return;
        push(l), push(r-1);
        bool cl=false, cr=false;
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (cl) calc(l-1);
            if (cr) calc(r);
            if (l&1) apply(l++, v), cl=true;
            if (r&1) apply(--r, v), cr=true;
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
};

