// Mo's algo, O(q*S+n*n/S), q is query idx's, [l,r] closed
// update(idx, +-1) adds/dels to some DS (tot is cur ans)
ll S = sqrtl(n);
sort(q.begin(), q.end(), [&](ll a, ll b) {
	if (l[a]/S != l[b]/S) return l[a]/S < l[b]/S;
	return l[a]/S%2 ? r[a]>r[b] : r[a]<r[b];
});

ll curl=0, curr=-1;
for (auto i:q) {
	while(curr<r[i]) update(++curr, 1);
	while(curl>l[i]) update(--curl, 1);
	while(curr>r[i]) update(curr--, -1);
	while(curl<l[i]) update(curl++, -1);

	ans[i] = tot;
}
