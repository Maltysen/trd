//Dijkstra
vector<pl> graph[N];
ll n, d[N], p[N];

void dijk(int s) {
    fill_n(d, n + 1, LLONG_MAX);
    d[s] = p[s] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> q;
    q.emplace(0, s);
    while(q.size()) {
        ll du = q.top().K, u = q.top().V;
        q.pop();
        if(du == d[u]) for(pl e : graph[u]) {
            ll v = e.K, dv = du + e.V;
            if(dv < d[v]) d[v] = dv, p[v] = u, q.emplace(dv, v);
        }
    }
}
