#include <bits/stdc++.h>
#define NAME "GAME"
#define lim 0
using namespace std;
void sub1() {
    /* N, M, Q <= 1000
    Duyệt tplt của mỗi nguyên tố
    */
}
void sub2() {
    /* Đồ thị là 1 cây (không có chu trình đơn > 1)
    LCA
    với mỗi (u, v) trong query, thì ta kiểm tra (u, LCA(u, v)) có trùng màu với (v, LCA(u, v)) không
    Gọi mảng up[u] là số lượng cạnh có cùng màu liên tiếp tính từ u -> gốc
    z = LCA(u, v)
    up[u] >= depth[z] - depth[u] có nghĩa là đi được
    */
}
void sub3() {
    /* Vì số lượng nt đi được trong 1 truy vấn <= 300
    Nên ta xây dựng 1 DSU riêng cho mỗi nguyên tố ấy
    Với mỗi nguyên tố w, ta sẽ có DSU riêng cho nguyên tố đó
    Khi thêm cạnh (u, v, w) thì sẽ là DSU[w].union(u, v);
    Với mỗi truy vấn (x, y) thì phải làm sao đây?
    trong DSU[w] nó sẽ lưu những tplt mà đường đi của chúng chỉ có nt w
    code unverified bởi vì chắc gì tổng nguyên tố toàn bộ truy vấn <= 300?
    */
}
void sub4() {
    /* sub 4: không có giới hạn gì hết
    => nhận xét: đồ thị chỉ có m cạnh, nên một số các nguyên tố sẽ có tần suất xuất hiện ít hơn, 
    một số thì nhiều hơn. Và số lượng nguyên tố mà có tuần suất nhiều thì chắc chắn sẽ ít hơn
    => sử dụng kĩ thuật chia căn
    => chia dựa vào block, rồi phân ra làm hai phần heavy, light
    => phần heavy cần xử lí tối ưu, và phần light thì chỉ cần xử lí trâu

    gọi block = 100

    -phần heavy là những nguyên tố có tần suất xuất hiện cao hơn (tần suất > 100)
    -phần lighty là những nguyên tố có tuần xuất hiện ít hơn (tần suất <= 100

    -cách xử lí phần heavy: xử lí giống sub 3(tại vì số lượng nguyên tố nhỏ hơn)
    -cách xử lí phần light: (offline) 
    với mỗi nguyên tố trong light, ta cần tìm các tplt có cạnh là nguyên tố đó.
    duyệt mọi đỉnh u, v trong tplt và tăng đáp án lên
    vấn đề: vì số cặp (u, v) ở đây có thể rất lớn nên mình chỉ cần lưu lại những cặp (u, v)
    nào mà thực sự xuất hiện trong danh sách các truy vấn là đượcl
    */
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
}