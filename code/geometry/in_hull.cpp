// O(lg(n)) check if point is in convex hull
bool in_hull(pt p, pair<vector<pt>, vector<pt>>& h) {
    // change to true if border counts as inside
	if(Z(p - *h.first.begin()) || Z(p - *h.second.begin())) return false;
	if(p < *h.first.begin() || *h.second.begin() < p) return false;
	auto u = upper_bound(all(h.first), p);
	auto d = lower_bound(h.second.rbegin(), h.second.rend(), p);
    // change to > -EPS if border counts as "inside"
	return CRS(*u - p, *(u - 1) - p) > EPS && CRS(*(d - 1) - p, *d - p) > EPS;
}
