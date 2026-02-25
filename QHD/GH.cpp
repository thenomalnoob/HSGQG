//mục tiêu: 60% sub đầu
#include <bits/stdc++.h>
#define NAME "GH"
#define lim 100001
#define fi first
#define se second
using namespace std;
int N, T, a[lim][2], b[lim][2], c[lim];
long long res;
unsigned long long dpk[101][101], dph[101][101];
bool catchu = 1;
void sub12() {
    for(int i = 1; i <= N; ++i) c[i] = a[i][0];
    sort(c + 1, c + N + 1);
    for(int i = 1; i <= T; ++i) res += c[i];
    for(int i = 1; i <= T; ++i) res += min(b[i][0], b[i][1]);
}
void sub31() {
    //vector lưu trạng thái: (best, person), (second, person)
    pair<int, int> mn[2]; //kho
    mn[0].fi = 1e9;
    mn[1].fi = 1e9;
    for(int i = 1; i <= N; ++i) {
        if(a[i][0] < mn[0].fi) mn[0].fi = a[i][0];
        if(a[i][1] < mn[1].fi) mn[1].fi = a[i][1];
    }
    res = min(mn[0].fi + b[1][0], mn[1].fi + b[1][1]);
}
void sub32() {
    pair<int, int> mn[2], se[2]; //kho
    mn[0].fi = se[0].fi = 1e9;
    mn[1].fi = se[1].fi = 1e9;
    for(int i = 1; i <= N; ++i) {
        if(a[i][0] < mn[0].fi) se[0] = mn[0], mn[0] = {a[i][0], i};
        else if(a[i][0] < se[0].fi) se[0] = {a[i][0], i};

        if(a[i][1] < mn[1].fi) se[1] = mn[1], mn[1] = {a[i][1], i};
        else if(a[i][1] < se[1].fi) se[1] = {a[i][1], i};
    }
    res = 1e18;
    //Kho 0 - 1, 2
    res = min(res, 0LL + mn[0].fi + se[0].fi + b[1][0] + b[2][0]);
    //Kho 1 - 1, 2
    res = min(res, 0LL + mn[1].fi + se[1].fi + b[1][1] + b[2][1]);
    //Kho 0 - 1, 1 - 2
    if(mn[0].se != mn[1].se) res = min(res, 0LL + mn[0].fi + mn[1].fi + b[1][0] + b[2][1]);
    else res = min(res, 0LL + b[1][0] + b[2][1] + min(mn[0].fi + se[1].fi, se[0].fi + mn[1].fi));
    //Kho 0 - 2, 1 - 1
    if(mn[0].se != mn[1].se) res = min(res, 0LL + mn[0].fi + mn[1].fi + b[1][1] + b[2][0]);
    else res = min(res, 0LL + b[1][1] + b[2][0] + min(mn[0].fi + se[1].fi, se[0].fi + mn[1].fi));
}
/*void subdp() {
    memset(dpk, -1, sizeof dpk);
    dpk[0][0] = 0;
    //i = 0
    for(int x = 1; x <= N; ++x)for(int j = min(x, T); j; --j) 
         {
            dpk[0][j] = min(dpk[0][j], dpk[0][j - 1] + a[x][1]);
        }
    for(int x = 1; x <= N; ++x)for(int i = min(x, T); i; --i)
         {
            dpk[i][0] = min(dpk[i][0], dpk[i - 1][0] + a[x][0]);
        }
    for(int x = 1; x <= N; ++x)for(int i = min(x, T); i; --i) {
        for(int j = min(x, T) - i; j; --j) {
             {
                dpk[i][j] = min(dpk[i][j], min(dpk[i - 1][j] + a[x][0], dpk[i][j - 1] + a[x][1]));
            }
        }
    }

    memset(dph, -1, sizeof dph);
    dph[0][0] = 0;
    for(int x = 1; x <= T; ++x)for(int j = min(x, T); j; --j) 
         {
            dph[0][j] = min(dph[0][j], dph[0][j - 1] + b[x][1]);
        }
    for(int x = 1; x <= T; ++x)for(int i = min(x, T); i; --i)
         {
            dph[i][0] = min(dph[i][0], dph[i - 1][0] + b[x][0]);
        }
    for(int x = 1; x <= N; ++x)for(int i = min(x, T); i; --i) {
        for(int j = min(x, T) - i; j; --j) {
             {
                dph[i][j] = min(dph[i][j], min(dph[i - 1][j] + b[x][0], dph[i][j - 1] + b[x][1]));
            }
        }
    }
    unsigned long long tmp = -1;
    for(int i = 0; i <= T; ++i) tmp = min(tmp, dpk[i][T - i] + dph[i][T - i]);
    res = tmp;
}*/
void subdp() {
    const long long INF = (1LL<<60);

    // --- dpk: chọn nhân viên ---
    for (int i = 0; i <= T; ++i)
        for (int j = 0; j <= T; ++j)
            dpk[i][j] = INF;
    dpk[0][0] = 0;

    // xử lý từng nhân viên x; cập nhật ngược để mỗi nhân viên được dùng nhiều nhất 1 lần
    for (int x = 1; x <= N; ++x) {
        int limit = min(x, T); // tối đa có thể chọn x người trong x nhân viên
        for (int i = limit; i >= 0; --i) {
            for (int j = limit - i; j >= 0; --j) {
                if (dpk[i][j] == INF) continue;
                if (i + 1 <= T) {
                    long long val = dpk[i][j] + (long long)a[x][0]; // chọn x cho kho0
                    if (val < dpk[i+1][j]) dpk[i+1][j] = val;
                }
                if (j + 1 <= T) {
                    long long val = dpk[i][j] + (long long)a[x][1]; // chọn x cho kho1
                    if (val < dpk[i][j+1]) dpk[i][j+1] = val;
                }
            }
        }
    }

    // de[i] = tổng a nhỏ nhất khi chọn T nhân viên, trong đó i người đi kho0
    static long long de[lim];
    for (int i = 0; i <= T; ++i) {
        de[i] = INF;
        if (T - i >= 0 && T - i <= T) de[i] = dpk[i][T - i];
    }

    // --- dph: chọn đơn hàng (requests) ---
    for (int i = 0; i <= T; ++i)
        for (int j = 0; j <= T; ++j)
            dph[i][j] = INF;
    dph[0][0] = 0;

    // Xử lý tuần tự từng request q (1..T). Cập nhật ngược như trên.
    for (int q = 1; q <= T; ++q) {
        int limit = min(q, T);
        for (int i = limit; i >= 0; --i) {
            for (int j = limit - i; j >= 0; --j) {
                if (dph[i][j] == INF) continue;
                if (i + 1 <= T) {
                    long long val = dph[i][j] + (long long)b[q][0]; // gán request q cho kho0
                    if (val < dph[i+1][j]) dph[i+1][j] = val;
                }
                if (j + 1 <= T) {
                    long long val = dph[i][j] + (long long)b[q][1]; // gán request q cho kho1
                    if (val < dph[i][j+1]) dph[i][j+1] = val;
                }
            }
        }
    }

    // dh[i] = tổng b nhỏ nhất khi gán T requests, trong đó i request cho kho0
    static long long dh[lim];
    for (int i = 0; i <= T; ++i) {
        dh[i] = INF;
        if (T - i >= 0 && T - i <= T) dh[i] = dph[i][T - i];
    }

    // Kết hợp: lấy i sao cho de[i] + dh[i] nhỏ nhất
    long long ans = INF;
    for (int i = 0; i <= T; ++i) {
        if (de[i] == INF || dh[i] == INF) continue;
        long long cur = de[i] + dh[i];
        if (cur < ans) ans = cur;
    }

    if (ans >= INF/2) res = -1; // hoặc theo spec bạn muốn
    else res = ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N >> T;
    for(int i = 1; i <= N; ++i) cin >> a[i][0];
    for(int i = 1; i <= N; ++i) cin >> a[i][1], catchu &= a[i][0] == a[i][1];
    for(int i = 1; i <= T; ++i) cin >> b[i][0];
    for(int i = 1; i <= T; ++i) cin >> b[i][1];
    /*
    if(catchu) sub12();
    else if(T == 1) sub31();
    else if(T == 2) sub32();
    else*/ 
    subdp();
    cout << res;
}