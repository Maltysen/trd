@HASH
// Factor numbers in O(n^1/3 /log(n))
// Needs primes up to O(n^1/3)
#define ff(x) abs((x = (mul(x, x) + c)%n) -y)
ll rho(ll n, ll u=2, ll c=1) {
    ll x=u, g=1, q=1, z, y;

    for (int l=1,i,k; g<2; l*=2) {
        y = x;
        for (i=l; --i;) ff(x);

        for (k=0; k<l && g<2; k+=128) {
            z = x;
            for (i=min(128,l-k); i--;)
                q=mul(q, ff(x));
            g = gcd(q, n);
        }
    }
    if (g==n)
        while(g=gcd(n, ff(z)), g<2);

    return g-n? g: rho(n, u+1, c+1);
}

auto fac(ll n) {
    map<ll,ll> f;
    for (ll p:primes) {
        if (p*p*p>n) {
            if (!miller_rabin(p=n)) {
                p = roundl(sqrtl(n));
                if (p*p-n) p=rho(n);
            }
            f[p]++, f[n/p]++;
            f.erase(1);
            return f;
        }
        while (n%p==0) n/=p, f[p]++;
    }
}

