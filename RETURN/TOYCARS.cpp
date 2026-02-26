/*
Vì việc truy cập vùng nhớ ngẫu nhiên rất tốn kém, máy tính đã cấp cho tôi một RAM có K khu, lưu tối đa được K address
Các truy vấn của tôi có khoảng [1, N]. Và tôi truy vấn đến P lần
Máy tính biết trước được dãy truy vấn của tôi. Nếu như RAM đã đầy, nó có thể thay thế address của một khu cho truy vấn
Nhưng vì việc này gây cache miss, hãy tính số lần thay thế ít nhất
1 <= K <= N <= 100000, 1 <= P <= 500000
SOL: 
Nếu như RAM đã đầy, và cần thay thế, tôi sẽ thay thế con xa nhất sẽ được truy vấn trong mảng (có thể là inf)
Hết.
*/
#include <bits/stdc++.h>
#define NAME "TOYCARS"
#define lim 100001
using namespace std;
unsigned N, K, P, car[lim * 5], nxt[lim * 5], nxt_of_use[lim], sz, cnt;
bool is_using[lim];
priority_queue<unsigned> pq;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> N >> K >> P;
    sz = K;
    for(unsigned i = 1; i <= P; ++i) cin >> car[i];
    memset(nxt_of_use, -1, sizeof nxt_of_use);
    for(unsigned i = P; i; --i) {
        nxt[i] = nxt_of_use[car[i]];
        nxt_of_use[car[i]] = i;
    }
    for(unsigned i = 1; i <= P; ++i) {
        if(!is_using[car[i]]) {
            if(pq.size() == sz) { //vứt đi một con
                unsigned u = pq.top();
                pq.pop();
                if(u != -1) is_using[car[u]] = 0;
            }
            pq.push(nxt[i]);
            is_using[car[i]] = 1;
            ++cnt;
        }
        else { //sẽ đè lên con cũ, trở thành rác. Con cũ không quá i và sẽ là những con nhỏ nhất
            pq.push(nxt[i]);
            ++sz;
        }
    }
    cout << cnt;
}