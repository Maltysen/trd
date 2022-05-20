// 3D Cross product
vec cross(const vec&a, const vec&b) {
	return {
		a.y*b.z - b.y*a.z,
		b.x*a.z - a.x*b.z,
		a.x*b.y - a.y*b.x
	};
}
