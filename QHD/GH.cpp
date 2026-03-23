#include <bits/stdc++.h>
#define lim 100001
#define f first
#define s second
#define pii pair<int, int>
using namespace std;
int N, T, cur;
pii A[lim], B[lim];
long long dph[lim], dpk[lim];
priority_queue<pii> pqd;
priority_queue<int, vector<int>, greater<int>> pqmn;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("GH.inp", "r")) {
        freopen("GH.inp", "r", stdin);
        freopen("GH.out", "w", stdout);
    }
    cin >> N >> T;
    for(int i = 1; i <= N; ++i) cin >> A[i].f;
    for(int i = 1; i <= N; ++i) cin >> A[i].s, A[i].s -= A[i].f;
    for(int i = 1; i <= T; ++i) cin >> B[i].f;
    for(int i = 1; i <= T; ++i) cin >> B[i].s, B[i].s -= B[i].f;
    sort(A + 1, A + N + 1); //n nhân viên có quãng đường đến kho 1 là nhỏ nhất
    sort(B + 1, B + T + 1);
    for(int i = 1; i <= T; ++i) dph[0] += A[i].f, pqd.push({A[i].f - A[i].s, i}); //delta lớn nhất
    for(int i = T + 1; i <= N; ++i) pqmn.push(A[i].s); //min b free, có thể 0 không có phần tử nào
    cur = T;
    for(int h = 1; h <= T; ++h) {
        //so sánh b_free-a_i và -delta_i nhỏ nhất có thể
        auto [d, ind] = pqd.top();
        int b = pqmn.empty() ? 2e9 : pqmn.top();
        if(b - A[cur].f < -d) {
            dph[h] = dph[h - 1] + b - A[cur].f;
            pqmn.pop();
            pqmn.push(A[cur].s);
            A[cur].f = -1;
        }
        else {
            dph[h] = dph[h - 1] - d;
            pqd.pop();
            pqmn.push(A[ind].s);
            A[ind].f = -1;
        }
        while(A[cur].f == -1) --cur;
    }
}