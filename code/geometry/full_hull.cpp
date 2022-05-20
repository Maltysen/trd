vector<pt> full_hull(vector<pt>& pts) {
	auto h = get_hull(pts);
	h.first.pop_back(), h.second.pop_back();
	for(pt p : h.second) h.first.push_back(p);
	return h.first;
}
