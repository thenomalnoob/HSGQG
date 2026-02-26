/*
Cho n câu chuyện. Truyện thứ i được sáng tạo vào ngày r_i và cần p_i ngày để viết.
Mỗi câu chuyện càng làm xong sớm thì có hệ số phạt (số ngày) càng ít
Tính tổng hệ số phạt nhỏ nhất
2
1 5
2 1
Ngày 2: Xong 20% t1. Ngày 3: Xong 100% t2. Ngày 4, 5, 6, 7: Xong 100% t1. Hệ số phạt: 3 + 7 = 10
Ở đây ta có thể dùng vector timeline
Timeline: 
*/
#include <bits/stdc++.h>
#define NAME "PULP"
#define lim 0
using namespace std;
int n, r, p;
vector<pair<int, int>> timeline;
long long penalty, pre_t;
priority_queue<int, vector<int>, greater<int>> pq; 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> r >> p;
        timeline.emplace_back(r, p);
    }
    sort(timeline.begin(), timeline.end());
    for(auto [r, p] : timeline) {
        //Những gì đã xong trước đó
        while(!pq.empty()) {
            int t = pq.top();
            pq.pop();
            if(pre_t + t <= r) {
                pre_t += t;
                penalty += pre_t;
                //cout << "truyen da duoc xong vao ngay " << pre_t << '\n';
            }
            else {
                pq.push(t - (r - pre_t));
                //cout << "truyen con dang do so ngay " << t - (r - pre_t) << '\n';
                break;
            }
        }
        //Thêm vào
        pq.push(p);
        pre_t = r;
        //cout << "pen = " << penalty << ' ' << " time now = " << pre_t << '\n';
    }
    while(!pq.empty()) {
        int t = pq.top();
        pq.pop();
        pre_t += t;
        penalty += pre_t;
    }
    cout << penalty;
}