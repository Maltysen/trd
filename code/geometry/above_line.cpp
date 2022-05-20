bool above_line(pt p, line l) { return CRS(p - l.P, l.D) > 0; }
