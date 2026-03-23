#include <bits/stdc++.h>
#define NAME "TABLE"
#define lim 512
using namespace std;
//fenwick tree: SR - S(R-1) = sR
/*
up1: [L, R): +w tại aL, -w tại aR
up2: +wL tại aL, -wR tại a_R
*/
bool upd;
long long dp[lim][lim], a[lim][lim];
int m, n, Q, type, x, y, u, v, w;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> m >> n >> Q;
    for(int i = 1; i <= m; ++i) for(int j = 1; j <= n; ++j) cin >> dp[i][j];
    for(int i = m; i; --i) for(int j = n; j; --j) dp[i][j] -= dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1]; 
    while(Q--) {
        cin >> type >> x >> y >> u >> v;
        if(type == 1) {
            cin >> w;
            if(w) upd = 1;
            dp[x][y] += w;
            dp[x][v + 1] -= w;
            dp[u + 1][y] -= w;
            dp[u + 1][v + 1] += w;
        }
        else {
            if(upd) {
                for(int i = 1; i <= m; ++i) for(int j = 1; j <= n; ++j) {
                    a[i][j] = dp[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
                }
                for(int i = 1; i <= m; ++i) for(int j = 1; j <= n; ++j) {
                    a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
                }
                upd = 0;
            }
            cout << a[u][v] - a[x - 1][v] - a[u][y - 1] + a[x - 1][y - 1] << '\n';
            }
        }
}