#include <bits/stdc++.h>
#define NAME "FLIGHT"
#define lim 200001
using namespace std;
int n, b[lim], l[lim], zip[lim];
long long BIT[lim], res;
void update(int p, long long v) {
    for(; p <= n; p += p & -p) {
        BIT[p] = max(BIT[p], v);
    }
}
long long get(int p) {
    long long res = 0;
    for(; p; p &= p - 1) {
        res = max(res, BIT[p]);
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
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> l[i];
        zip[i] = l[i];
    }
    sort(zip + 1, zip + n + 1);
    for(int i = 1; i <= n; ++i) {
        l[i] = lower_bound(zip + 1, zip + n + 1, l[i]) - zip;
    }
    for(int i = 1; i <= n; ++i) {
        update(l[i], get(l[i] - 1) + b[i]);
    }
    cout << get(n);
}