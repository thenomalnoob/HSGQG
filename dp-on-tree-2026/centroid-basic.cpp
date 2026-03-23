//Tìm u bất kì, mà nếu lấy u làm gốc thì mọi cây con của nó có kích thước <= n / 2
#include <bits/stdc++.h>
#define NAME "CENTROID"
#define lim 200001
using namespace std;
int n, u, v, dp[lim];
vector<int> adj[lim];
int dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            dp[u] += dfs(v, u);
        }
    }
    return ++dp[u];
}
int centroid(int u) {
    for(int v : adj[u]) {
        if(dp[v] > n / 2) {
            dp[u] = n - dp[v];
            dp[v] = n;
            return centroid(v);
        }
    }
    return u;
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
    dfs(1, 0);
    cout << centroid(1);
}