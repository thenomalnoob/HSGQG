#include <bits/stdc++.h>
#define NAME "PHATQUA"
#define limbo 300001
#define lim 2001
using namespace std;
int N, K, A[limbo];
long long dp[lim][lim], lt[lim][lim];
long long cur_S, max_S, l_S, r_S;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N >> K;
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    if(K == 1) {
        for(int i = 1; i <= N; ++i) {
            cur_S = max(cur_S, 0LL) + A[i];
            max_S = max(max_S, cur_S);
        }
        cout << max_S;
    }
    else if(N <= 2000) {
        /*
        lt[a][b]: result of the tank with a segments & b elements, element b in segment a
        dp[a][b]: result of the task with a segments & b elements
        So:
        lt[a][b] = max(dp[a-1][b-1],lt[a][b-1])+A[i]
        dp[a][b] = max(dp[a][b-1],lt[a][b]) 
        */
        for(int j = 1; j <= K; ++j) {
            for(int i = j; i <= N; ++i) {
                lt[j][i] = max(dp[j - 1][i - 1], lt[j][i - 1]) + A[i];
                dp[j][i] = max(dp[j][i - 1], lt[j][i]);
            }
        }
        for(int i = 1; i <= N; ++i) max_S = max(max_S, dp[i][N]);
        cout << max_S;
    }
    else {
        int i = 1;
        for(; A[i] >= 0 && i != N + 1; ++i) {
            l_S += A[i];
        }
        if(i == N + 1) return cout << l_S, 0;
        for(int j = N; j != i; --j) {
            r_S += A[j];
        }
        cout << (K == 1 ? max(l_S + r_S + A[i], max(l_S, r_S)) : l_S + r_S);
    }
}