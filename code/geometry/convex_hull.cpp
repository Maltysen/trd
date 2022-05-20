// Convex Hull
void do_hull(vector<pt>& pts, vector<pt>& h) {
	for(pt p : pts) {
		while(h.size() > 1 && CRS(h.back() - p, h[h.size() - 2] - p) <= EPS)
			h.pop_back();
		h.push_back(p);
	}
}

pair<vector<pt>, vector<pt>> get_hull(vector<pt>& pts) {
	vector<pt> hu, hd;
	sort(all(pts)), do_hull(pts, hu);
	reverse(all(pts)), do_hull(pts, hd);
	return {hu, hd};
}
