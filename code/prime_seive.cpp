// Prime Seive
for (ll i=2; i<NN; i++)
    if (!prime[i]) {
        prime[i] = i;
        for (ll j=i*i;j<NN;j+=i) if(!prime[j]) prime[j]=i;
    }

