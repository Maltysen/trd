// O(n) check if point in polygon
bool in_poly(pt p, vector<pt>& poly) {
	line l = line(p, {INF, INF * PI}, 1);
	bool ans = false;
	pt lst = poly.back(), tmp;
	for(pt q : poly) {
		line s = line(q, lst, 1); lst = q;
		if(on_line(p, s)) return false; //change if border not included
		else if(intsct(l, s, tmp)) ans = !ans;
	}
	return ans;
}
