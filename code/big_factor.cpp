#define ff(x) abs((x = (mul(x, x) + c)%n)-y)
ll rho(ll n, ll x0=2, ll c=1) {
    ll x=x0, g=1, q=1, z, y;

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
        for (;g=gcd(ff(z), n), g<2;);

    return g-n?g:rho(n, x0+1, c+1);
}

auto fac(ll n) {
    #define rr(x) {f[x]++; return f;}
    map<ll,ll> f;
    for (ll p:primes) {
        if (p*p*p>n) break;
        while (n%p==0) n/=p, f[p]++;
    }
    if (n==1) return f;
    if (miller_rabin(n)) rr(n)

    ll x = roundl(sqrtl(n));
    if (x*x==n) rr(x)

    f[x=rho(n)]++;
    rr(n/x)
}

