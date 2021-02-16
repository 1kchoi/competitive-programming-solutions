// CCC '14 S5 - Lazy Fox
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, best[NMAX], pdist[NMAX], pbest[NMAX];
vii A;
vector<ar<ll, 3>> pairs;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    A.PB({0, 0});
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        A.PB({x, y});
    }

    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            ll dx = A[i][0] - A[j][0];
            ll x2 = dx * dx;
            ll dy = A[i][1] - A[j][1];
            ll y2 = dy * dy;
            pairs.PB({x2 + y2, i, j});
        }
    }
    sort(all(pairs));
    for (ar<ll, 3> x : pairs) {
        ll d = x[0], i = x[1], j = x[2];
        cout << d << " " << i << " " << j << endl;
        if (pdist[i] < d) {
            pdist[i] = d;
            pbest[i] = best[i];
        }
        if (pdist[j] < d) {
            pdist[j] = d;
            pbest[j] = best[j];
        }
        best[i] = max(best[i], pbest[j] + 1);
        if (i) best[j] = max(best[j], pbest[i] + 1);
    }

    cout << best[0] << endl;


    return 0;
}
