#include <bits/stdc++.h>
#define NAME "BAI1"
#define lim 5001
#define OFFSET 2000000
#define limbo (OFFSET << 1 | 1)
using namespace std;
int n, q, a[lim], L, R, _[limbo];
constexpr int *cnt = _ + OFFSET;
queue<int> added;
long long query[lim][lim];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> q;
    for(L = 1; L <= n; ++L) cin >> a[L];
    for(L = n - 2; L; --L) {
        for(R = L + 1; R <= n; ++R) {
            /*a[L] = -(a[x] + a[R]), -a[x] = a[L] + a[R]
            a[R] = - a[L] - a[x]
            tức là cứ dịch chuyển R sang phải thì ta sẽ thêm vào u_map 1 số - a[L] - a[x]
            */
            //query[L][R] = query[L + 1][R] + query[L][R - 1] - query[L + 1][R - 1] + cnt(x in (L, R) that a[x] = -(a[L] + a[R]))
            query[L][R] = query[L + 1][R] + query[L][R - 1] - query[L + 1][R - 1] + cnt[- a[L] - a[R]];
            added.push(a[R]);
            ++cnt[a[R]];
        }
        while(!added.empty()) {
            cnt[added.front()] = 0;
            added.pop();
        }
    }
    while(q--) {
        cin >> L >> R;
        cout << query[L][R] << '\n';
    }
}