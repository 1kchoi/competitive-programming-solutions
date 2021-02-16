// IOI '05 P1 - Garden
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define LMAX 255
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int R, C, N, K;
ll G[LMAX][LMAX], pf[LMAX][LMAX], ans;
vector<ar<int, 4>> A;
bool found = false;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> R >> C >> N >> K;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        G[a][b]++;
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            pf[i][j] = pf[i][j - 1] + G[i][j];
        }
    }
    for (int i = 1; i <= C; i++) {
        for (int j = i; j <= C; j++) {
            ll sum = pf[1][j] - pf[1][i - 1];
            int upper = 1, lower = 1;
            while (upper <= R) {
                if (sum == K) {
                    A.PB({i, lower, j, upper});
                    upper++;
                    sum += pf[upper][j] - pf[upper][i - 1];
                }
                else if (sum > K) {
                    sum -= pf[lower][j] - pf[lower][i - 1];
                    lower++;
                }
                else { // sum < K
                    upper++;
                    sum += pf[upper][j] - pf[upper][i - 1];
                }
            }
        }
    }
    sort(all(A));

    memset(&ans, INF, sizeof(ans));
    for (int i = 0; i + 1 < sz(A); i++) {
        for (int j = i + 1; j < sz(A); j++) {
            if (A[i][0] <= A[j][0] && A[j][0] <= A[i][2]) {
                continue;
            }
            if (A[i][1] <= A[j][1] && A[j][1] <= A[i][3]) {
                continue;
            }
            found = true;
            ll sum1 = 2 * (A[i][2] - A[i][0] + A[i][3] - A[i][1]);
            ll sum2 = 2 * (A[j][2] - A[j][0] + A[j][3] - A[j][1]);
            ans = min(ans, sum1 + sum2);
        }
    }

    if (!found) cout << "NO" << endl;
    else cout << ans << endl;

    return 0;
}
