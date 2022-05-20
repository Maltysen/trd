// Finds the two lines tangent to two circles
vector<line> circTangents(circ c1, circ c2) {
	pt d = c2.C - c1.C;
	ld dr = c1.R - c2.R, d2 = norm(d), h2 = d2 - dr * dr;
	if(Z(d2) || h2 < 0) return {};
	vector<line> ans;
	for(ld sg : {-1, 1}) {
		pt u = (d * dr + d * I * sqrt(h2) * sg) / d2;
		ans.push_back(line(c1.C + u * c1.R, c2.C + u * c2.R, 1));
	}
	if(Z(h2)) ans.pop_back();
	return ans;
}
