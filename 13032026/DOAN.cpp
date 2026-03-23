#include <bits/stdc++.h>
#define NAME "DOAN"
#define lim 502
#define pii pair<int, int>
using namespace std;
int n, a[lim];
vector<int> v;
struct {
    int prev_l;
    int sum;
} dp[lim];
int max_l, min_sum, fit_i;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    a[0] = 1001;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i - 1] > a[i]) {
            dp[i].prev_l = dp[i - 1].prev_l + 1;
            dp[i].sum = dp[i - 1].sum + a[i]; 
        }
        else {
            dp[i].prev_l = 1;
            dp[i].sum = a[i];
        }
        if(dp[i].prev_l > max_l || dp[i].prev_l == max_l && dp[i].sum < min_sum) {
            max_l = dp[i].prev_l;
            min_sum = dp[i].sum;
            fit_i = i;
        }
    }
    cout << max_l << '\n' << min_sum << '\n';
    for(int i = fit_i - max_l + 1; i <= fit_i; ++i) cout << a[i] << ' ';
}