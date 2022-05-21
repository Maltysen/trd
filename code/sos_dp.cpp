// SOS dp, init H[mask] to og array
for(ll i=0; i<N; ++i)
	for(ll mask=0; mask<(1<<N); ++mask)
		if(mask & (1<<i)) H[mask] += H[mask^(1<<i)];
