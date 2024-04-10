// Aho-Corasick suffix automaton
lk[0] = -1;
queue<int> q; q.push(0);
while (q.size()) {
    int u = q.front(); q.pop();

    for (int c=0; c<10; ++c) {
        if (~child[u][c]) {
            int v = child[u][c], j=lk[u];
            trans[u][c] = v;
            while (~j && child[j][c]==-1) j=lk[j];
            if (~j) lk[v] = child[j][c];
            q.push(v);
        } else {
            if (lk[u]==-1) trans[u][c]=u;
            else trans[u][c] = trans[lk[u]][c];
        }
    }
}
