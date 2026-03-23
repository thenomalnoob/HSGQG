/*
Trinh Van Duc Anh
THPT Chuyen Lam Son
*/
#include <bits/stdc++.h>
#define NAME "PASS"
#define base 31
#define lim 2001
using namespace std;
string X, Y;
long long curX[2], cur[2], cnt;
const int MOD[2] = {1000000007, 1000000009};
string sX, sY;
unordered_set<long long> s;
set<string> ss;
int max_l;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> X >> Y;
    if(X.size() > 2000 || Y.size() > 2000) return cout << X.size() * Y.size(), 0;
    for(int i = 0; i < X.size(); ++i) {
        for(int hi = 0; hi < 2; ++hi) {
            cur[hi] = curX[hi] = (curX[hi] * base + X[i] - 'a' + 1) % MOD[hi];
        }
        for(int j = 0; j < Y.size(); ++j) {
            for(int hi = 0; hi < 2; ++hi) {
                cur[hi] = (cur[hi] * base + Y[j] - 'a' + 1) % MOD[hi];
            }              
            s.insert(cur[0] << 32LL | cur[1]);
        }
    }
    cout << s.size();
}