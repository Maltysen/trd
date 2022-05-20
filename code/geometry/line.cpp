struct line {
	pt P, D; bool S = false;
	line(pt p, pt q, bool b = false) : P(p), D(q - p), S(b) {}
	line(pt p, ld th) : P(p), D(polar((ld)1, th)) {}
};
