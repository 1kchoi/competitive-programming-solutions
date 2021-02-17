// UTS Open '21 P5 - State Taxes
// unfinished
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(5e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct node {
    ll salary, val;
    bool payday;
};

int N, Q;
node S[1 << 20];

void apply(int i, ll x, bool b, int l, int r) {
    S[i].salary += x;
    S[i].payday |= b;
    if (l == r && S[i].payday) {
        S[i].val += S[i].salary;
        S[i].payday = false;
    }
}

void push(int i, int l, int r) {
    if (l == r) return;
    if (S[i].salary == 0 && !S[i].payday) return;
    int m = (l + r) / 2;
    apply(2 * i, S[i].salary, S[i].payday, l, m);
    apply(2 * i + 1, S[i].salary, S[i].payday, m + 1, r);
    S[i].payday = false;
    S[i].salary = 0;
}

void pupdate(int pos, ll x, int i = 1, int l = 0, int r = N - 1) {
    if (l == r) {
        cout << i << endl;
        S[i].salary = x;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) {
        pupdate(pos, x, 2 * i, l, m);
    }
    else {
        pupdate(pos, x, 2 * i + 1, m + 1, r);
    }
}

void update(int l1, int r1, ll x, int i = 1, int l2 = 0, int r2 = N - 1) {
    push(i, l2, r2);
    if (l1 <= l2 && r2 <= r1) {
        S[i].salary += x;
        return;
    }
    int m2 = (l2 + r2) / 2;
    if (l1 <= m2) {
        update(l1, r1, x, 2 * i, l2, m2);
    }
    if (m2 < r1) {
        update(l1, r1, x, 2 * i + 1, m2 + 1, r2);
    }
}

void payworkers(int l1, int r1, int i = 1, int l2 = 0, int r2 = N - 1) {
    push(i, l2, r2);
    if (l1 <= l2 && r2 <= r1) {
        S[i].payday = true;
        if (l2 == r2) {
            S[i].val += S[i].salary;
            S[i].payday = false;
        }
        return;
    }
    int m2 = (l2 + r2) / 2;
    if (l1 <= m2) {
        payworkers(l1, r1, 2 * i, l2, m2);
    }
    if (m2 < r1) {
        payworkers(l1, r1, 2 * i + 1, m2 + 1, r2);
    }
}

ll query(int pos, int i = 1, int l = 0, int r = N - 1) {
    if (l == r) {
        if (S[i].payday) {
            S[i].val += S[i].salary;
            S[i].payday = false;
        }
        return S[i].val;
    }
    push(i, l, r);
    int m = (l + r) / 2;
    if (pos <= m) {
        return query(pos, 2 * i, l, m);
    }
    else {
        return query(pos, 2 * i + 1, m + 1, r);
    }
}

ll query2(int pos, int i = 1, int l = 0, int r = N - 1) {
    if (l == r) {
        return S[i].salary;
    }
    push(i, l, r);
    int m = (l + r) / 2;
    if (pos <= m) {
        return query2(pos, 2 * i, l, m);
    }
    else {
        return query2(pos, 2 * i + 1, m + 1, r);
    }
}
ll query3(int pos, int i = 1, int l = 0, int r = N - 1) {
    if (l == r) {
        return S[i].payday;
    }
    push(i, l, r);
    int m = (l + r) / 2;
    if (pos <= m) {
        return query3(pos, 2 * i, l, m);
    }
    else {
        return query3(pos, 2 * i + 1, m + 1, r);
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        cout << setw(3) << query(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << setw(3) << query2(i) << " ";
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << setw(3) << query3(i) << " ";
    }
    cout << endl;
    cout << endl;
}

void printAns() {
    for (int i = 0; i < N; i++) {
        ll x = query(i);
        cout << "ANSWER TO " << i << ": " << x << endl;
    }
    cout << endl;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        pupdate(i, x);
        //print();
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) { // update
            int l, r; ll d; cin >> l >> r >> d;
            //cout << t << " " << l << " " << r << " " << d << endl;
            --l; --r;
            update(l, r, d);
        }
        else { // payday
            int l, r; cin >> l >> r;
            //cout << t << " " << l << " " << r << endl;
            --l; --r;
            payworkers(l, r);
        }
        //print();
    }
    cout << "PRINTING ANS RIGHT NOW" << endl;
    printAns();


    return 0;
}
