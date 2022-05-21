// LIS (Longest increasing subsequence)
vl lis;
ll n, a[N];

    F(i, 0, n) {
        // change to > for strictly increasing
        if(lis.empty() || a[i] >= lis.back()) lis.push_back(a[i]);
        // change to lower_bound for strictly increasing
        else *upper_bound(all(lis), a[i]) = a[i];
    }
    cout << lis.size() << '\n';
