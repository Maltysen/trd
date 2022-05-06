// Inverse segtree operations
    T query(int p) {
        T res = id;
        for (p+=n; p>0; p/=2) res = f(res, t[p]);
        return res;
    }

    void modify(int l, int r, T v) {
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (l&1) t[l] = f(t[l], v), l++;
            if (r&1) --r, t[r] = f(t[r], v);
        }
    }


