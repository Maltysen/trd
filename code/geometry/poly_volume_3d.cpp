ld signedPolyVolume(const V& p, const L& trilist) {
	ld v = 0;
	for (auto i : trilist) v += p[i.a].cross(p[i.b]).dot(p[i.c]);
	return v / 6;
}
