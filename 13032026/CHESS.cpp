#include <bits/stdc++.h>
#define NAME "CHESS"
#define lim 200002
#define MOD 1000000007
using namespace std;
int h, w, n, u, v;
long long fac[lim], inv_fac[lim], res;
long long power(long long a, unsigned b) {
    long long res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
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
    cin >> h >> w >> n;
    fac[0] = 1;
    for(int i = 1; i <= h + w; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[h + w] = power(fac[h + w], MOD - 2);
    for(int i = h + w; i; --i) {
        inv_fac[i - 1] = inv_fac[i] * i % MOD;
    }
    res = fac[h + w - 2] * inv_fac[h - 1] % MOD * inv_fac[w - 1] % MOD;
    while(n--) {
        cin >> u >> v;
        res -= fac[u + v - 2] * inv_fac[u - 1] % MOD * inv_fac[v - 1] % MOD
        * fac[n - u + n - v] % MOD * inv_fac[n - u] % MOD * inv_fac[n - v] % MOD;
    }
    cout << res;
}