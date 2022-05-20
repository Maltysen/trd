// Circle line intersection
vector<pt> intsctCL(circ c, line l) {
    vector<pt> v, ans;
    if(Z(dist_to(c.C, line(l.P, l.P + l.D, 0)))) v = {c.C + c.R * U(l.D), c.C - c.R * U(l.D)};
    else v = intsctCC(c, circ{refl_pt(c.C, l), c.R});
	for(pt p : v) if(on_line(p, l)) ans.push_back(p);
    return ans;
}
