@HASH
// Min Cost Max Flow, ran in 139ms for n=400, m=15000
struct edge {
    int to, cap, cost, rev;
    edge() {
        to = cap = cost = rev = 0;
    }
    edge(int _t, int _c, int _w, int _r) {
        to = _t;
        cap = _c;
        cost = _w;
        rev = _r;
    };
};

vector<edge> g[N];
int iter[N];
ll dis[N];
bool vis[N];

void addedge(int from, int to, int cap, int cost) {
    g[from].emplace_back(to, cap, cost, g[to].size());
    g[to].emplace_back(from, 0, -cost, g[from].size() - 1);
}

bool getdis(int S, int T) {
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.emplace(S);
    dis[S] = 0;
    vis[S] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = 0;

        for (edge &e : g[x])
            if (e.cap && dis[e.to] > dis[x] + e.cost) {
                dis[e.to] = dis[x] + e.cost;

                if (!vis[e.to]) {
                    vis[e.to] = 1;
                    q.emplace(e.to);
                }
            }
    }

    return dis[T] != 0x3f3f3f3f3f3f3f3fll;
}

pair<ll, int> dfs(int x, int T, int flow) {
    if (x == T)
        return {0, flow};

    vis[x] = 1;

    pair<ll, int> res;

    for (int &i = iter[x]; i < g[x].size(); i++) {
        edge &e = g[x][i];

        if (!vis[e.to] && e.cap && dis[x] + e.cost == dis[e.to] && flow) {
            pair<ll, int> cur = dfs(e.to, T, min(e.cap, flow));
            res.first += cur.first + cur.second * e.cost;
            res.second += cur.second;
            e.cap -= cur.second;
            g[e.to][e.rev].cap += cur.second;
            flow -= cur.second;

            if (res.second) {
                vis[x] = 0;
                return res;
            }
        }
    }

    vis[x] = 0;
    return res;
}

pair<ll, ll> mcf(int S, int T) {
    pair<ll, ll> res;

    while (getdis(S, T)) {
        memset(iter, 0, sizeof(iter));
        pair<ll, int> cur;

        while ((cur = dfs(S, T, 1e9)) != make_pair(0ll, 0)) {
            res.first += cur.first;
            res.second += cur.second;
        }
    }

    return res;
}

