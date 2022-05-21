@HASH
// Li Chao Tree
typedef complex<ld> pt;
#define x real
#define y imag

ld f(pt a, ld x) {return (pt{x, -1} * a).x();}

pt line[4 * NN];

void add_line(pt nw, int v = 1, int l = 0, int r = NN) {
    int m = (l + r) / 2;
    bool lef = f(nw, l) < f(line[v], l);
    bool mid = f(nw, m) < f(line[v], m);
    if(mid) {
        swap(line[v], nw);
    }
    if(r - l == 1) return;
    else if(lef != mid) add_line(nw, 2 * v, l, m);
    else add_line(nw, 2 * v + 1, m, r);
}

ld get(int x, int v = 1, int l = 0, int r = NN) {
    int m = (l + r) / 2;
    if(r - l == 1) return f(line[v], x);
    else if(x < m) return min(f(line[v], x), get(x, 2 * v, l, m));
    else return min(f(line[v], x), get(x, 2 * v + 1, m, r));
}
