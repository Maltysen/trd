// digit dp
ll dp[20][2]; //also can have auxiliary info
int r[20]; //number as digit array
int n; //length

#define DP dp[pos][is_eq]
ll solve(int pos, bool is_eq) {
	if (~DP) return DP;
	if (pos==n)    
		return DP=1; //check for predicate (here it is p(x)=True)

	DP = 0;
	for (int i=0;i<=(is_eq?r[pos]:9);i++)
		DP += solve(pos+1, is_eq && i==r[pos]);

	return DP;
}
