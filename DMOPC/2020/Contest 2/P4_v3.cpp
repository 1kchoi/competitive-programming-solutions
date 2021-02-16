// DMOPC '20 Contest 2 P4 - Hungry Pigeons
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(5e4+5)
#define MMAX (int)(5e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N, M, worms[MMAX], flag[MMAX], seg[2 * NMAX];
vi pigeons;
vii wormsort;
oset S;

void pull(int i) {
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

void update(int pos, ll x, int i = 1, int l = 0, int r = N - 1) {
    if (l == r) {
        seg[i] += x;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) {
        update(pos, x, 2 * i, l, m);
    }
    else {
        update(pos, x, 2 * i + 1, m + 1, r);
    }
    pull(i);
}

ll query(int l1, int r1, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        return seg[i];
    }
    int m2 = (l2 + r2) / 2;
    ll retl = LLONG_MAX, retr = LLONG_MAX;
    if (l1 <= m2) {
        retl = query(l1, r1, 2 * i, l2, m2);
    }
    if (m2 < r1) {
        retr = query(l1, r1, 2 * i + 1, m2 + 1, r2);
    }
    return min(retl, retr);
}

void debugFlag() {
    cout << "PRINTING FLAG" << endl;
    for (int i = 0; i < M; i++) {
        cout << i << " " << worms[i] << " " << flag[i] << endl;
    }
    cout << endl;
}

void debugAns() {
    cout << "PRINTING ANS" << endl;
    for (int i = 0; i < M; i++) {
        update(flag[i], 1);
        cout << i << " " << query(0, N - 1) << endl;
    }
    cout << endl;
}

void debugWormsort() {
    cout << "PRINTING WORMSORT" << endl;
    for (int i = 0; i < sz(wormsort); i++) {
        cout << i << " " << wormsort[i][0] << " " << wormsort[i][1] << endl;
    }
    cout << endl;
}

void debugS() {
    cout << "PRINTING S: ";
    for (ii x : S) {
        cout << x[1] << " ";
    }
    cout << endl;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(flag, -1, sizeof(flag));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        pigeons.PB(x);
    }
    for (int i = 0; i < M; i++) {
        cin >> worms[i];
        wormsort.PB({worms[i], i});
    }
    sort(all(wormsort));
    sort(all(pigeons));
    debugWormsort();

    int pigi = 0;
    for (int i = 0; i < sz(wormsort); i++) {
        cout << "ENTERING " << i << endl;
        ii x = wormsort[i];
        while (pigi < N && wormsort[i][0] >= pigeons[pigi]) {
            cout << "hit!" << endl;
            for (int j = 0; sz(S) && j < M / N; j++) {
                cout << "j = " << j << endl;
                ii event = *S.find_by_order(0);
                flag[event[0]] = pigi;
                S.erase(event);
            }
            pigi++;
            debugS();
            cout << "pigi = " << pigi << endl;
        }
        S.insert({x[1], x[0]});
    }
    debugFlag();

    // above, fix case when multiple birds have same beak length, distribute evenly


    for (int i = 0; i < M; i++) {
        if (flag[i] >= 0) update(flag[i], 1);
        if (i) cout << " ";
        cout << query(0, N - 1);
    }
    cout << endl;

    //debugAns();

    return 0;
}
