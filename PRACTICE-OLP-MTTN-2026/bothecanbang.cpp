#include <bits/stdc++.h>
#define lim 501
using namespace std;
int N, card[lim], x, dp[lim][2], res;
bool visited[lim];
vector<int> adj[lim];
inline bool imbalance(int x, int y) {
    int l = 0, w = 0;
    for(int j = 1; j <= 6; ++j) {
        if((x & 31) < (y & 31)) ++l;
        else if((x & 31) > (y & 31)) ++w;
        x >>= 5, y >>= 5;
    }
    return l && !w || !l && w;
}
void rec(int u) {
    visited[u] = 1;
    for(int v : adj[u]) 
        if(!visited[v]) {
            rec(v);
            dp[u][0] += max(dp[v][0], dp[v][1]); //dp khong chua u
            dp[u][1] += dp[v][0]; //dp chua u
        }
    ++dp[u][1];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= 6; ++j) {
            cin >> x;
            card[i] <<= 5;
            card[i] += x;
        }
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = i + 1; j <= N; ++j) {
            if(imbalance(card[i], card[j])) {
                adj[i].push_back(j), adj[j].push_back(i);
            }
        }
    }
    for(int i = 1; i <= N; ++i) {
        if(!visited[i]) {
            rec(i);
        }
    }
    for(int i = 1; i <= N; ++i) {
        res = max(res, max(dp[i][0], dp[i][1]));
    }
    cout << N - res;
}   