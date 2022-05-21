@HASH
// Gaussian elimination modulo M
vector<int> where;
int solve_system(mat a, vector<ll> &b) {
    int n=a.size(), m=a[0].size();
    for (int i=0; i<n; ++i) a[i].push_back(b[i]);

    where.assign(m, -1);
    for (int col=0,row=0; col<m && row<n; ++col) {
        int k=row; while (k<n && !a[k][col]) ++k;
        if (k==n) continue;
        swap(a[k], a[row]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                ll c = a[i][col] * inv(a[row][col]) %M;
                for (int j=col; j<=m; ++j)
                    ( a[i][j] += M - a[row][j]*c%M )%=M;
            }
        ++row;
    }

    b.assign(m, 0);
    for (int i=0; i<m; ++i) if (~where[i])
        b[i] = a[where[i]][m] * inv(a[where[i]][i]) %M;

    for (int i=0; i<n; ++i) {
        ll sum = 0;
        for (int j=0; j<m; ++j)
           ( sum += b[j] * a[i][j] )%=M;
        if (sum != a[i][m])
            return 0;
    }

    return !!count(all(where), -1) + 1;
}
