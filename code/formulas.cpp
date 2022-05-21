// Catalan formula
C[n] = 1/(n+1) * choose(2*n, n)

// Number of labeled trees
n^(n-2)

// Stirling # second kind
// # of ways to partition set of n elements into k nonempty subsets
S(i, 1) = 1
S(i, j) = S(i-1, j-1) + j*S(i-1, j)

x^n = sum{k=0 to n} S(n,k)*perm(x, k)

// For binomial var X on n trial with prob p
E[perm(x, k)] = perm(n, k)*p^k
