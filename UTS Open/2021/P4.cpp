// Codeforces ####A - NAME
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N, M, A[22][22], edges[22][2], ans, winner;

ll test() {
    ll ret = 0;
    for (int i = 0; i < N; i++) {
        int c = 0;
        for (int j = 0; j < N; j++) {
            c += A[i][j];
        }
        if (c & 1) ret++;
    }
    return ret;
}

void setG(ll mask, bool setting) {
    for (int i = 0; i < M; i++) {
        if (!(mask & (1 << i))) {
            A[edges[i][0]][edges[i][1]] = setting;
            A[edges[i][1]][edges[i][0]] = setting;
        }
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll x, y; cin >> x >> y;
        --x; --y;
        A[x][y] = true;
        A[y][x] = true;
        edges[i][0] = x;
        edges[i][1] = y;
    }

    for (ll mask = 0; mask < (1 << M); mask++) {
        setG(mask, 0);
        ll cand = test();
        if (cand > ans) {
            ans = cand;
            winner = mask;
        }
        setG(mask, 1);
    }

    cout << ans << endl;
    ll offcount = 0;
    for (int i = 0; i < M; i++) {
        offcount += !(winner & (1 << i));
    }
    cout << offcount << endl;
    for (int i = 0; i < M; i++) {
        if (!(winner & (1 << i))) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;


    return 0;
}
