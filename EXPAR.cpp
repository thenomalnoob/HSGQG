#include <bits/stdc++.h>
#define pb push_back
#define po pop_back
using namespace std;
string S, oe;
bool x, y, tmp;
vector<int> num;
char pri[128];
vector<int> st;//postfix
queue<int> q, qp;//infix
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> S >> oe;
    pri['x'] = oe.front() == 'O';
    cin >> oe;
    pri['y'] = oe.front() == 'O';
    pri['+'] = pri['-'] = 3;
    pri['*'] = 6;
    for(int i = 0; i < S.size(); ++i) {
        if(S[i] == 'x' || S[i] == 'y') q.push(pri[S[i]]);
        else if(S[i] == '+' || S[i] == '-') q.push(3);
        else if(S[i] == '*') q.push(6);
        else if(!isdigit(S[i + 1])) q.push(S[i] & 1);
    }
    while(!q.empty()) {
        if(q.front() < 2) qp.push(q.front());
        else {
            if(!st.empty() && st.back() >= q.front()) qp.push(st.back()), st.po();
            st.pb(q.front());
        }
        q.pop();
    }
    while(!st.empty()) qp.push(st.back()), st.po();
    while(!qp.empty()) {
        if(qp.front() < 2) num.pb(qp.front());
        else {
            tmp = num.back();
            num.pop_back();
            if(qp.front() == 3) num.back() ^= tmp;
            else num.back() &= tmp;
        }
        qp.pop();
    }
    cout << (num.back() ? "Odd" : "Even");
}