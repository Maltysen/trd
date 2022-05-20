// Geometry Header
typedef complex<ld> pt;

#define X real()
#define Y imag()
#define CRS(a, b) (conj(a) * (b)).Y
#define DOT(a, b) (conj(a) * (b)).X
#define U(p) ((p) / abs(p))
#define Z(x) (abs(x) < EPS)

ld PI = acosl(-1), INF = 1e20, EPS = 1e-12;
pt I = {0, 1};
