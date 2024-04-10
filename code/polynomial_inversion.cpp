// Polynomial inversion: D¯(x) = A¯(x)*inv(B¯(x)) % x^(n-m+1)
vl inv(vl a) {
    if (a.size()==1) return {inv(a[0])};
    vl p0, p1;
    for (ll i=0; i<a.size(); ++i)
        if (i%2==0) p0.push_back(a[i]);
        else p1.push_back((M-a[i])%M);
    vl p1s = p1*p1; p1s.insert(p1s.begin(), 0);
    vl t = inv((p0*p0 - p1s)%((a.size() + 1)/2));
    
    p0 = p0*t, p1 = p1*t; 
    vl r0, r1(1);
    for (ll c:p0) r0.push_back(c), r0.push_back(0);
    for (ll c:p1) r1.push_back(c), r1.push_back(0);
    return (r0 + r1)%(a.size());
}
