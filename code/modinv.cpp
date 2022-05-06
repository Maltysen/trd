ll inv(ll a, ll b=M){return 1<a ? b - inv(b%a,a)*b/a : 1;}
