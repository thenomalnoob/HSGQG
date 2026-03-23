#include <bits/stdc++.h>
#define NAME ""
#define lim 200001
using namespace std;
int t, n, k, c, u, v;
vector<vector<int>> adj;
void program() {
    vector<int> d(n + 1), h1(n + 1), h2(n + 1);
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> t;
    while(t--) {
        cin >> n >> k >> c;

    }
}