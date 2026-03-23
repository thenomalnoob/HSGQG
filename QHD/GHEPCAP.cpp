#include <bits/stdc++.h>
#define NAME "MATCH"
#define lim 4000001
#define MOD 1000000007
using namespace std;
int N, A, B, i;
long long P[lim], D[lim], rP[lim], res;
int power(long long a, unsigned b) {
    long long res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N >> A >> B;
    for(P[0] = 1, i = 1; i <= N; ++i) {
        P[i] = P[i - 1] * i % MOD;
    }
    for(rP[N] = power(P[N], MOD - 2), i = N; i; --i) {
        rP[i - 1] = rP[i] * i % MOD;
    }
    for(D[0] = 1, i = 1; i <= N; ++i) {
        D[i] = (D[i - 1] * i + (i & 1 ? -1 : 1) + MOD) % MOD;
    }
    for(i = A; i <= B; ++i) {
        res = (res + (P[N] * D[N - i] % MOD) * (rP[i] * rP[N - i] % MOD)) % MOD;
    }
    cout << res;
}