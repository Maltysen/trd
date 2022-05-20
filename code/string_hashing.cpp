// String Hashing
#define M 1000000321
#define OP(x, y) pl operator x (pl a, pl b) { return { a.K x b.K, (a.V y b.V) % M }; }
OP(+, +) OP(*, *) OP(-, + M -)
mt19937 gen(__builtin_ia32_rdtsc());
uniform_int_distribution<ll> dist(256, M - 1);

#define H(i, l) (h[(i) + (l)] - h[i] * p[l])
#define EQ(i, j, l) (H(i, l) == H(j, l))

string s;
pl p[N], h[N];

    p[0] = { 1, 1 }, p[1] = { dist(gen) | 1, dist(gen) };
    F(i, 1, s.size() + 1) p[i] = p[i - 1] * p[1], h[i] = h[i - 1] * p[1] + pl{s[i - 1], s[i - 1]};
