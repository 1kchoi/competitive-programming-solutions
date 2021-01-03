// CCCHK '15 S1 - Finding number of pairs
#include <bits/stdc++.h>
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
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, M, ans;
vi A;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;
    A.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(all(A));

    int i = 0, j = N - 1;
    while (i < j) {
        if (A[i] + A[j] <= M) {
            ans += j - i;
            ans %= MOD;
            ++i;
        }
        else {
            --j;
        }
    }

    cout << ans << endl;

    return 0;
}
