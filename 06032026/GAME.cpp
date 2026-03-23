/*
Trinh Van Duc Anh
THPT Chuyen Lam Son
*/
#include <bits/stdc++.h>
#define NAME "GAME"
#define lim 100001
using namespace std;
#define pii pair<int, int>
int N, M, Q, u, v, w, cnt;
vector<pii> adj[lim];
pii query[lim];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N >> M;
    for(int i = 1; i <= M; ++i) {
        cin >> u >> v >> w;
        if(u > v) swap(u, v);
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    cin >> Q;
    for(int i = 1; i <= Q; ++i) {
        cin >> u >> v;
        if(u > v) swap(u, v);
        cnt = 0;
        for(auto [x, y] : adj[u]) {
            if(y == v) ++cnt;
        }
        cout << cnt << '\n';
    }
}