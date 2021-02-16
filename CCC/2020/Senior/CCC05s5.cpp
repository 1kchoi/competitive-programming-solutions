// CCC '05 S5 - Pinball Ranking
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
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
typedef tree<ll, null_type, greater_equal<ll>, rb_tree_tag,
            tree_order_statistics_node_update> oset;

ll N, ans;
oset T;
vector<ll> A;

void setIO(bool b, string name = "input") {
    ios::sync_with_stdio(0); cin.tie(0);
    if (!b) return;
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    setIO(1);

    cin >> N;
    for (int i = 0; i < N; i++) {
        double X; cin >> X;
        T.insert(X);
        ans += T.order_of_key(X) + 1.0;
    }
    cout << fixed << setprecision(2) << ans / (N + 0.0) << endl;

    return 0;
}
