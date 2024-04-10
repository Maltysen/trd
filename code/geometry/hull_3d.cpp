// 3D Convex hull
struct PR {
	void ins(int x) { (a == -1 ? a : b) = x; }
	void rem(int x) { (a == x ? a : b) = -1; }
	int cnt() { return (a != -1) + (b != -1); }
	int a, b;
};
struct H { P3 q; int a, b, c; };

vector<H> hull3d(const vector<P3>& A) {
	assert(A.size() >= 4);
	vector<vector<PR>> E(A.size(), vector<PR>(A.size(), {-1, -1}));
#define E(x,y) E[f.x][f.y]
	vector<H> FS;
	auto mf = [&](int i, int j, int k, int l) {
		P3 q = (A[j] - A[i]).cross((A[k] - A[i]));
		if (q.dot(A[l]) > q.dot(A[i]))
			q = q * -1;
		H f{q, i, j, k};
		E(a,b).ins(k); E(a,c).ins(j); E(b,c).ins(i);
		FS.push_back(f);
	};
	F(i,0,4) F(j,i+1,4) F(k,j+1,4) mf(i, j, k, 6 - i - j - k);

	F(i,4,A.size()) {
		F(j,0,FS.size()) {
			H f = FS[j];
			if(f.q.dot(A[i]) > f.q.dot(A[f.a])) {
				E(a,b).rem(f.c);
				E(a,c).rem(f.b);
				E(b,c).rem(f.a);
				swap(FS[j--], FS.back());
				FS.pop_back();
			}
		}
		int nw = FS.size();
		F(j,0,nw) {
			H f = FS[j];
#define C(a, b, c) if (E(a,b).cnt() != 2) mf(f.a, f.b, i, f.c);
			C(a, b, c); C(a, c, b); C(b, c, a);
		}
	}
	for (H& it : FS) if ((A[it.b] - A[it.a]).cross(
		A[it.c] - A[it.a]).dot(it.q) <= 0) swap(it.c, it.b);
	return FS;
};
