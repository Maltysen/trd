@HASH
// Gaussian elimination on ld's
vector<int> where;
int solve_system(mat a, vector<ld> &b) {
    int n=a.size(), m=a[0].size();
    for (int i=0; i<n; ++i) a[i].push_back(b[i]);

    where.assign(m, -1);
    for (int col=0,row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs(a[i][col]) > abs(a[sel][col])) sel = i;

        if (abs(a[sel][col]) < EPS) continue;

        for (int i=col; i<=m; ++i) swap(a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i!=row) {
                ld c = a[i][col]/a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    b.assign(m, 0);
    for (int i=0; i<m; ++i) if (~where[i])
        b[i] = a[where[i]][m]/a[where[i]][i];

    for (int i=0; i<n; ++i) {
        ld sum = 0;
        for (int j=0; j<m; ++j)
            sum += b[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS) return 0;
    }

    return !!count(all(where), -1) + 1;
}
