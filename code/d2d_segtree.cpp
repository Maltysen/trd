struct seg {
    T* t;
    int n;

    void init(int nn) {
        n = nn;
        t = new T[2*n];
        fill(t, t+2*n, id);
    }

    void modify(int p, T value) {  // set value at position p
      for (p+=n, t[p] = value; p /= 2;) t[p] = f(t[2*p], t[2*p+1]);
    }

    T query(int l, int r) { // fold f on interval [l, r)
      T resl=id, resr=id;
      for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l&1) resl = f(resl, t[l++]);
        if (r&1) resr = f(t[--r], resr);
      }
      return f(resl, resr);
    }
};


struct d2dseg {
    using I=pair<K, int>;
    int n;
    K* keys;
    seg *s;
    I **k;

    int m;
    #define CH if(p>=n || (m=s[2*p].n)==s[2*p+1].n)
    void init() {
        k = new I*[2*n];
        s = new seg[2*n];
        for (int p=2*n; --p;) CH { 
            s[p].init(2*m + !m);
            k[p] = new I[s[p].n];
            I** y = k+2*p;
            m ? *merge(*y, *y+m, y[1], y[1]+m, k[p])
                : *k[p] = {keys[p-n], p-n};
        }
    }

    #define lb(a...) lower_bound(k[p], k[p]+s[p].n, I{a}) - k[p]
    void modify(int p, T v) {
        I a{keys[p], p};
        for (p+=n; p; p/=2) CH s[p].modify(lb(a), v);
    }

    #define qq(i) p=i, res=f(res, s[p].query(lb(a, -1), lb(b, -1)));
    T query(int l, int r, K a, K b) {
        int p;
        T res=id;
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (l&1) qq(l++)
            if (r&1) qq(--r)
        }
        return res;
    }
};
