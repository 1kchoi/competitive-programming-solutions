// CCC '17 S5 - RMT
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1.5e5+5)
#define ROOTNMAX 400
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, K, M, Q, A[NMAX], B[ROOTNMAX], L[NMAX], rotation[NMAX], brute[NMAX];
vi allinline[NMAX];
vii lastinline[NMAX];

void update(ll X) {
    for (int i = 0; i < sz(lastinline[X]); i++) {
        ll index1 = lastinline[X][i][1] - rotation[X];
        ll index2 = lastinline[X][(i - 1 + sz(lastinline[X])) % sz(lastinline[X])][1] - rotation[X];
        index1 += sz(allinline[X]); index1 %= sz(allinline[X]);
        index2 += sz(allinline[X]); index2 %= sz(allinline[X]);
        B[lastinline[X][i][0]] -= A[allinline[X][index1]];
        B[lastinline[X][i][0]] += A[allinline[X][index2]];
    }
    rotation[X]++;
    rotation[X] %= sz(allinline[X]);
}

ll getVal(int pos) {
    ll line = L[pos];
    ll index = lower_bound(all(allinline[line]), pos) - allinline[line].begin();
    index += sz(allinline[line]);
    index -= rotation[line];
    index %= sz(allinline[line]);
    return A[allinline[line][index]];
}

ll query(ll st, ll en) {
    ll ans = 0;

    ll lblock = st / K, rblock = en / K;
    if (lblock == rblock) { // special case: L and R in same block
        for (int i = st; i <= en; i++) {
            ans += getVal(i);
        }
    }
    else {
        for (int i = st; i < (lblock + 1) * K; i++) {
            ans += getVal(i);
        }
        for (int i = lblock + 1; i < rblock; i++) {
            ans += B[i];
        }
        for (int i = rblock * K; i <= en; i++) {
            ans += getVal(i);
        }
    }

    return ans;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> M >> Q;
    K = (ll)(sqrt(N));
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        allinline[L[i]].PB(i);
        if (sz(lastinline[L[i]]) && lastinline[L[i]][sz(lastinline[L[i]]) - 1][0] == i / K) {
            lastinline[L[i]][sz(lastinline[L[i]]) - 1][1] = sz(allinline[L[i]]) - 1;
        }
        else {
            lastinline[L[i]].PB({i / K, sz(allinline[L[i]]) - 1});
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        brute[i] = A[i];
        B[i / K] += A[i];
    }

    while (Q--) {
        int t; cin >> t;
        if (t == 1) { // query l r
            ll l, r; cin >> l >> r;
            --l; --r;
            cout << query(l, r) << endl;
        }
        else { // update x
            ll x; cin >> x;
            update(x);
        }
    }


    return 0;
}
