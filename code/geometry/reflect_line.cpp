line reflect_line(line r, line l) {
	pt p; if(intsct(r, l, p) - 1) return r;
	return line(p, p + INF * (p - refl_pt(r.P, l)), 1);
}
