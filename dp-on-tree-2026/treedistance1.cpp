#include <bits/stdc++.h>
#define NAME ""
#define lim 200001
using namespace std;
int n, u, v, h1[lim], h2[lim], r1, r2;
vector<int> adj[lim];
int bfs1(int s) {
    queue<int> q;
    q.push(s);
    int lst;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(v != s && !h1[v]) {
                h1[v] = h1[u] + 1;
                q.push(v);
            }
        }
        lst = u;
    }
    return lst;
}
int bfs2(int s) {
    queue<int> q;
    q.push(s);
    int lst;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(v != s && !h2[v]) {
                h2[v] = h2[u] + 1;
                q.push(v);
            }
        }
        lst = u;
    }
    return lst;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    r1 = bfs1(1);
    r2 = bfs2(r1);
    memset(h1, 0, sizeof h1);
    r1 = bfs1(r2);
    for(int i = 1; i <= n; ++i) {
        cout << max(h1[i], h2[i]) << ' ';
    }
}