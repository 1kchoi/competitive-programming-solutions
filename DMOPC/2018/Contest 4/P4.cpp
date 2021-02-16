// DMOPC '18 Contest 4 P4 - Dr. Henri and Lab Data
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, QN, A[NMAX], bit[NMAX], ans[NMAX];
vector<ar<ll, 4>> Q;
vii sorted;

void update(int i, ll d) {
    for (; i <= N; i += (i & (-i))) bit[i] += d;
}

ll sum(int i) {
    ll r = 0;
    while (i) {
        r += bit[i];
        i -= (i & (-i));
    }
    return r;
}

ll query(int i, int j) {
    if (i > j) return query(j, i);
    return sum(j) - sum(i - 1);
}

void printBIT() {
    cout << "PRINTING BIT" << endl;
    for (int i = 1; i <= N; i++) {
        cout << bit[i] << " ";
    }
    cout << endl;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> QN;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        update(i, A[i]);
        sorted.PB({A[i], i});
    }
    for (int i = 0; i < QN; i++) {
        ll l, r, x; cin >> l >> r >> x;
        Q.PB({x, l, r, i});
    }
    sort(all(sorted));
    sort(all(Q));

    //printBIT();

    int i = 0;
    for (ar<ll, 4> v : Q) {
        ll x = v[0];
        //cout << "NOW PROCESSING " << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
        while (i < sz(sorted) && x > sorted[i][0]) {
            ll current = A[sorted[i][1]];
            update(sorted[i][1], -2 * current);
            i++;
        }
        //printBIT();
        ans[v[3]] = query(v[1], v[2]);
        //cout << ans[v[3]] << endl;
    }
    //cout << endl;
    for (int j = 0; j < QN; j++) {
        cout << ans[j] << endl;
    }

    return 0;
}
