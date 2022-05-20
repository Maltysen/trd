pt cl_pt_on_l(pt p, line l) {
	pt q = l.P + DOT(U(l.D), p - l.P) * U(l.D);
	if(on_line(q, l)) return q;
	return abs(p - l.P) < abs(p - l.P - l.D) ? l.P : l.P + l.D;
}
