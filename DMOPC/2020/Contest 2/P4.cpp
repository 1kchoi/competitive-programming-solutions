// DMOPC '20 Contest 2 P4 - Hungry Pigeons
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
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
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, M, birds[NMAX], worms[NMAX], dp[305], prefix[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> birds[i];
    }
    sort(birds, birds + N);
    for (int j = 0; j < M; j++) {
        cin >> worms[j];
    }

    for (int x = 1; x <= M; x++) {
        sort(worms, worms + x);
        memset(prefix, 0, sizeof(prefix));
        memset(dp, 0, sizeof(dp));
        int i2 = 0;
        for (int i = 0; i < x && i2 < N; i++) {
            while (i2 < N && worms[i] >= birds[i2]) {
                prefix[i2 + 1] = i;
                i2++;
            }
        }
        for (int i = i2; i < N; i++) {
            prefix[i + 1] = prefix[i2 - 1] + 1;
        }

        dp[0] = 0;
        dp[1] = prefix[1];
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], min(dp[j], (prefix[i] - prefix[j]) / (i - j)));
            }
        }

        cout << dp[N] << " ";
    }
    cout << endl;

    return 0;
}
