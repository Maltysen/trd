// Circle circle intersection
vector<pt> intsctCC(circ c1, circ c2) {
    pt d = c2.C - c1.C;
    ld d2 = norm(d);
    if(Z(d)) return {}; //concentric
    ld pd = (d2 + c1.R * c1.R - c2.R * c2.R) / 2;
    ld h2 = c1.R * c1.R - pd * pd / d2;
    if(h2 < 0) return {};
    pt p = c1.C + d * pd / d2, h = d * I * sqrtl(h2 / d2);
    if(Z(h)) return {p};
    return {p - h, p + h};
}
