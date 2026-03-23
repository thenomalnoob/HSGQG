#include <bits/stdc++.h>
#define NAME "CLOUD"
#define lim 2000
using namespace std;
int n, m;
long long res, tmp;
struct comp{
    int c, f, v;
    bool operator < (const comp other) const {
        return f < other.f;
    }
    bool operator > (const comp other) const {
        return f > other.f;
    }
} shop[lim], order[lim];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 0; i != n; ++i)
        cin >> shop[i].c >> shop[i].f >> shop[i].v;
    cin >> m;
    for(int j = 0; j != m; ++j)
        cin >> order[j].c >> order[j].f >> order[j].v;
    sort(shop, shop + n);
    sort(order, order + m);
    int i = 0;
    for(int j = 0; j != m; ++j) {
        tmp = 0;
        while(shop[i].f < order[j].f && i != n) ++i;
        if(i == n) return cout << res, 0;
        while(shop[i].c < order[j].c && i != n) tmp -= shop[i].v, order[j].c -= shop[i].c;
        if(i == n) return cout << res, 0;
        tmp -= shop[i].v;
        tmp += order[i].v;
        if(tmp > 0) res += tmp, shop[i].c -= order[j].c; 
    }
    cout << res;
}