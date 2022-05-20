pt centroid(vector<pt>& poly) {
	ld area = 0;
	pt lst = poly.back(), ans = {0, 0};
	for(pt p : poly) {
		area += CRS(lst, p);
		ans += CRS(lst, p) * (lst + p) / (ld)3;
		lst = p;
	}
	return ans / area;
}
