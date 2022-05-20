// CHT (Convex Hull Trick)
struct seg { ld x; ll m, b; };
vector<seg> hull;

void insert(ll m, ll b) { //lines inserted in inc. slope order for maxhull, dec. for minhull
	while(hull.size()) {
		seg s = hull.back();
		if(s.b + s.m * s.x > b + m * s.x) { //< for minhull
			if(s.m - m) hull.push_back({(b - s.b) / (ld)(s.m - m), m, b});
			return;
		}
		hull.pop_back();
	}
	hull = {{LLONG_MIN, m, b}};
}

ll query(ll x) {
	seg s = *--upper_bound(all(hull), x, [](ll a, seg b) { return a < b.x; });
	return s.b + s.m * x;
}
