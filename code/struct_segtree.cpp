// Segtree as a struct instead of a namespace
struct seg {
    T* t;
    int n;

    void init(int nn) {
        n = nn;
        t = new T[2*n];
        fill(t, t+2*n, id);
    }

    // modify and query are same as before
};
