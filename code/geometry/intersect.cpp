// Line-line intersection
bool parallel(pt d1, pt d2) { return Z(d1) || Z(d2) || Z(CRS(U(d1), U(d2))); }

bool on_line(pt p, line l) { return parallel(l.P - p, l.D) && (!l.S || DOT(l.P - p, l.P + l.D - p) <= EPS); }

ll intsct(line l1, line l2, pt& p) {
	if(parallel(l1.D, l2.D)) return on_line(l1.P, l2) ? 2 : 0; // not for segs
	pt q = l1.P + l1.D * CRS(l2.D, l2.P - l1.P) / CRS(l2.D, l1.D);
	if(on_line(q, l1) && on_line(q, l2)) { p = q; return 1; }
	return 0;
}
