@HASH
// Simplex
// max cx constraint Ax<=b, x>=0. -∞ no sol, ∞ no max, O(NM#pivs)
const ld eps = 1e-8, inf = 1/.0;
#define ltj(X) if(s == -1 || pair{X[j],N[j]} < pair{X[s],N[s]}) s=j

struct LPSolver {
	int m, n;
	vector<int> N, B;
	vector<vd> D;

	LPSolver(const vector<vd>& A, const vd& b, const vd& c) :
		m(b.size()), n(c.size()), N(n+1), B(m), D(m+2, vd(n+2)) {
			F(i,0,m) F(j,0,n) D[i][j] = A[i][j];
			F(i,0,m) B[i]=n+i, D[i][n]=-1, D[i][n+1]=b[i];
			F(j,0,n) N[j]=j, D[m][j]=-c[j];
			N[n] = -1, D[m+1][n] = 1;
		}

	void pivot(int r, int s) {
		ld *a = D[r].data(), inv = 1 / a[s];
		F(i,0,m+2) if (i != r && abs(D[i][s]) > eps) {
			ld *b = D[i].data(), inv2 = b[s] * inv;
			F(j,0,n+2) b[j] -= a[j] * inv2;
			b[s] = a[s] * inv2;
		}
		F(j,0,n+2) if (j != s) D[r][j] *= inv;
		F(i,0,m+2) if (i != r) D[i][s] *= -inv;
		D[r][s] = inv, swap(B[r], N[s]);
	}

	bool simplex(int phase) {
		int x = m + phase - 1;
		while (1) {
			int s = -1;
			F(j,0,n+1) if (N[j] != -phase) ltj(D[x]);
			if (D[x][s] >= -eps) return true;
			int r = -1;
			F(i,0,m) {
				if (D[i][s] <= eps) continue;
				if (r == -1 || pair{D[i][n+1] / D[i][s], B[i]}
				             < pair{D[r][n+1] / D[r][s], B[r]}) r = i;
			}
			if (r == -1) return false;
			pivot(r, s);
		}
	}

	ld solve(vd &x) {
		int r = 0;
		F(i,1,m) if (D[i][n+1] < D[r][n+1]) r = i;
		if (D[r][n+1] < -eps) {
			pivot(r, n);
			if (!simplex(2) || D[m+1][n+1] < -eps) return -inf;
			F(i,0,m) if (B[i] == -1) {
				int s = 0;
				F(j,1,n+1) ltj(D[i]);
				pivot(i, s);
			}
		}
		bool ok = simplex(1); x = vd(n);
		F(i,0,m) if (B[i] < n) x[B[i]] = D[i][n+1];
		return ok ? D[m][n+1] : inf;
	}
};

