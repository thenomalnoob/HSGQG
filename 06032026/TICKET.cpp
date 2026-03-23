/*
Trinh Van Duc Anh
THPT Chuyen Lam Son
*/
#include <bits/stdc++.h>
#define NAME "TICKET"
#define lim 100001
#define pii pair<int, int>
using namespace std;
int n, m, u, v, c, s, t, k, L, R, mid, h[lim]; //chứa max
bool visited[lim];
vector<pii> adj[lim];
bool bfs01(int s, int t, int mid, int k) {
    fill(h + 1, h + n + 1, lim);
    memset(visited, 0, sizeof visited);
    h[s] = 0;
    deque<int> dq;
    dq.push_back(s);
    while(!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        if(visited[u]) continue;
        visited[u] = 1;
        for(auto [c, v] : adj[u]) {
            if(c <= mid) {
                if(h[v] > h[u]) {
                    h[v] = h[u];
                    dq.push_front(v);
                }
            }
            else if(h[u] < k) {
                if(h[v] > h[u] + 1) {
                    h[v] = h[u] + 1;
                    dq.push_back(v);
                }
            }
        }
    }
    return visited[t];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v >> c;
        adj[u].emplace_back(c, v);
        adj[v].emplace_back(c, u);
    }
    cin >> s >> t >> k;
    for(L = 0, R = 1000000001, mid = L + R >> 1; L != R; mid = L + R >> 1) {
        bfs01(s, t, mid, k);
        if(h[t] <= k) R = mid;
        else L = mid + 1;
    }
    cout << L;
}