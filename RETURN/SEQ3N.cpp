#include <bits/stdc++.h>
#define NAME "CAU2"
#define lim 300005
using namespace std;
int i, N, N2, N3, A[lim], tmp;
long long max_prefix[lim], min_postfix[lim], res = -1e18;
priority_queue<int> max_elim;
priority_queue<int, vector<int>, greater<int>> min_elim;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N; N2 = N + N; N3 = N2 + N;
    for(i = 1; i <= N3; ++i) cin >> A[i];

    for(i = 1; i <= N; ++i) max_prefix[i] = max_prefix[i - 1] + A[i], min_elim.push(A[i]);
    for(; i <= N2; ++i) {
        max_prefix[i] = max_prefix[i - 1] + A[i];
        min_elim.push(A[i]);
        max_prefix[i] -= min_elim.top();
        min_elim.pop();
    }

    for(i = N3; i > N2; --i) min_postfix[i] = min_postfix[i + 1] + A[i], max_elim.push(A[i]);
    for(; i > N; --i) {
        min_postfix[i] = min_postfix[i + 1] + A[i];
        max_elim.push(A[i]);
        min_postfix[i] -= max_elim.top();
        max_elim.pop();
    }
    for(int i = N; i <= N2; ++i) {
        res = max(res, max_prefix[i] - min_postfix[i + 1]);
    }
    cout << res;
}
