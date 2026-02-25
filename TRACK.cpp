#include <bits/stdc++.h>
#define NAME "TRACK"
#define lim 500005
using namespace std;
int k, n, a, b, give[lim];
pair<int, int> sw[lim << 1];
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> k >> n;
    for(int i = 1; i <= k; ++i) pq.push(i);
    for(int i = 1; i <= n; ++i) {
        cin >> a >> b;
        sw[i - 1 << 1] = {a, i};
        sw[i - 1 << 1 | 1] = {b, -i};
    }
    sort(sw, sw + (n << 1));
    for(int i = 0; i < (n << 1); ++i) {
        if(sw[i].second < 0) pq.push(give[-sw[i].second]);
        else {
            if(pq.empty()) cout << 0 << ' ' << sw[i].second << '\n';
            else {
                give[sw[i].second] = pq.top();
                pq.pop();
            }
        }
    }
    for(int i = 1; i <= n; ++i) cout << give[i] << '\n';
}