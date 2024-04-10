// Catalan formula
C[n] = 1/(n+1) * choose(2*n, n)

// Stirling # second kind
// # of ways to partition set of n elements into k nonempty subsets
S(i, 1) = 1; S(i, j) = S(i-1, j-1) + j*S(i-1, j)

x^n = sum{k=0 to n} S(n,k)*perm(x, k)

// For binomial var X on n trial with prob p
E[perm(x, k)] = perm(n, k)*p^k

// Absorbing markov chain
P = [Q  R]    Then, N:=inv(1-Q)
    [0  1]

E[# steps before being absorbed when start at i] = t = (N dot 1)_i
P(i -> absorb at j) = (N*R)_ij
P(start at i, ever visit transient j) = (N-1)*inv(N's diag)
Var(# visits to trnsient j starting at i) = N(2*(N's diag) - 1) - (entrywise N^2)
Var(# of steps before being absorbed, starting at i) = (2N-1)t - (entrywise t^2)

// Derangements
d(n) = (n-1)* (d(n-1)+d(n-2)); d(0)=1, d(1)=0

// Euclid's formula
a=m^2-n^2, b=2mn, c=m^2+n^2 with m>n>0 coprime and differing parities

// Hockey-stick
sum{i=r to n} choose(i, r) = choose(n+1, r+1)
// Vandermonde
sum{k=0 to r} choose(m, k)*choose(n, r-k) = choose(m+n, r)

// Falhaubers formula
sum{i=0 to n} i^p = sum{i=0 to p} sterling(p, i)*fallingfactorial(n+1, i+1)/(i+1)

//From Kactl
//Triangles
Semiperimeter: $p=\dfrac{a+b+c}{2}$\\
Area: $A=\sqrt{p(p-a)(p-b)(p-c)}$\\
Circumradius: $R=\dfrac{abc}{4A}$\\
Inradius: $r=\dfrac{A}{p}$\\
median (half by area): m_a=1/2 sqrt{2b^2+2c^2-a^2}
angle bisector: s_a=sqrt{bc*[1-(a/(b+c))^2]}

// Sperical Coordinates
x = r\sin\theta\cos\phi & r = \sqrt{x^2+y^2+z^2}\\
y = r\sin\theta\sin\phi & \theta = \textrm{acos}(z/\sqrt{x^2+y^2+z^2})\\
z = r\cos\theta & \phi = \textrm{atan2}(y,x)

// Sums
1 + 2 + 3 + \dots + n &= \frac{n(n+1)}{2} \\
1^2 + 2^2 + 3^2 + \dots + n^2 &= \frac{n(2n+1)(n+1)}{6} \\
1^3 + 2^3 + 3^3 + \dots + n^3 &= \frac{n^2(n+1)^2}{4} \\

//Series
ln(1+x) = x-\frac{x^2}{2}+\frac{x^3}{3}-\frac{x^4}{4}+\dots,\,(-1<x\leq1)$$
sqrt{1+x} = 1+x/2-x^2/8+2x^3/32-5x^4/128... (-1<=x<=1)
