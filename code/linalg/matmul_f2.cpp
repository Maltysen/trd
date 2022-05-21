@HASH
// Matrix multiplication mod 2
mat matmul_f2(const mat &a, const mat &b) {
    int n = a.size();
    vector<bitset<BB>> A(n), B(b[0].size()), C(n);
    mat bt = transpose(b);
    for (int i=0; i<n; ++i)
        for (int j=0; j<a[0].size(); ++j) 
            A[i][j]=a[i][j], B[i][j]=bt[i][j];

    for (int i=0; i<n; ++i)
        for (int j=0; j<b[0].size(); ++j)
            C[i][j] = (A[i] ^ B[j]).count()&1;

    mat c(a.size(), vl(b[0].size()));
    for (int i=0; i<n; ++i)
        for (int j=0; j<b[0].size(); ++j) c[i][j] = C[i][j];
    return c;
}
