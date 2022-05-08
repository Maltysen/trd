// Miller rabin primality test (deterministic)
typedef uint64_t ull;

#define mul(a,b) (__uint128_t)a*b%n
ull binpow(ull x, ull y, ull n) {
    if (!y) return 1;
    return mul(binpow(mul(x,x), y/2, n), (y%2 ? x : 1));
}

bool miller_rabin(ull n) {
    if (n < 2) return 0;
    int s=__builtin_ctzll(n-1);

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n==a) return 1;
        ull x = binpow(a, n-1>>s, n);
        for (int r=0; x!=n-1 && r<s; ++r) x=mul(x,x);
        if (x!=n-1 && x-1) return 0;
    }
    return 1;
}


