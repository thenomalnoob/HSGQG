#include <bits/stdc++.h>
#define NAME "CAU2"
#define lim 200001
using namespace std;
int n, dp[lim][2], u, v;
vector<int> adj[lim];
void dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            dp[u][0] += dp[v][1];
        }
    }
    dp[u][1] = dp[u][0];
    for(int v : adj[u]) {
        if(v != p) {
            dp[u][1] = max(dp[u][1], dp[u][0] - dp[v][1] + dp[v][0] + 1);
        }
    }
}
bool d[lim];
int cnt;
void greedy(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            greedy(v, u);
            if(!d[u] && !d[v]) {
                d[u] = d[v] = true;
                ++cnt;
            }
        }
    }
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
    greedy(1, 0);
    cout << cnt;
}