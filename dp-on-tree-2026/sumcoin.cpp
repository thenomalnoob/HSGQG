#include <bits/stdc++.h>
#define NAME ""
#define lim 100001
using namespace std;
int N, C[lim], u, v;
long long dp[lim][2];
vector<int> adj[lim];
void dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            dp[u][0] += max(dp[v][1], dp[v][0]);
            dp[u][1] += dp[v][0];
        }
    }
    dp[u][1] = max(dp[u][1] + C[u], dp[u][0]);
    //Đảm bảo các dp[x][b] >= 0, vì có thể chọn hoặc không chọn mà 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> C[i];
    }
    for(int i = 1; i < N; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1][1];
}