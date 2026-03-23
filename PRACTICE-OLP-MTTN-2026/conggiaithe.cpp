#include <bits/stdc++.h>
#define NAME ""
#define lim 0
using namespace std;
long long N, c[3], d[3];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N >> c[0] >> c[1] >> c[2] >> d[0] >> d[1] >> d[2];
    cout << N - (c[0] + c[1] + c[2] - d[0] - d[1] - d[2]);
}