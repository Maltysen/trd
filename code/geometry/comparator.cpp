namespace std {
	bool operator<(pt a, pt b) { return Z(a.X - b.X) ? a.Y < b.Y : a.X < b.X; }
}
