// DMOPC '20 Contest 3 P4 - Bob and Typography
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e2+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A[NMAX], RA[NMAX], dp[NMAX][NMAX], rdp[NMAX][NMAX], mx[NMAX], rmx[NMAX];

int sum(int i, int j) {
    if (i) return A[j] - A[i - 1];
    return A[j];
}

int rsum(int i, int j) {
    if (i) return RA[j] - RA[i - 1];
    return RA[j];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

void printDP() {
    cout << "PRINTING DP" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << max(0, dp[j][i]);
        }
        cout << endl;
    }
    cout << endl;
    cout << "PRINTING RDP" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << max(0, rdp[j][i]);
        }
        cout << endl;
    }
    cout << endl;
    cout << "PRINTING MX" << endl;
    for (int i = 0; i < N; i++) {
        cout << i << " " << A[i] - (i ? A[i - 1] : 0) << " " << mx[i] << endl;
    }
    cout << endl;
    cout << "PRINTING RMX" << endl;
    for (int i = 0; i < N; i++) {
        cout << i << " " << RA[i] << " " << rmx[i] << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        RA[N - 1 - i] = A[i];
        if (i) {
            A[i] += A[i - 1];
            RA[N - 1 - i] += RA[N - i];
        }
    }

    memset(dp, -INF, sizeof(dp));
    memset(rdp, -INF, sizeof(rdp));
    for (int i = 0; i < N; i++) {
        dp[i][0] = 1;
        rdp[i][0] = 1;
        mx[i] = 1;
        rmx[i] = 1;
        for (int j = 1; j <= i; j++) {
            for (int k = 0; k < j; k++) {
                if (sum(k, j - 1) >= sum(j, i)) {
                    dp[i][j] = max(dp[i][j], dp[j - 1][k] + 1);
                }
                if (rsum(k, j - 1) >= rsum(j, i)) {
                    rdp[i][j] = max(rdp[i][j], rdp[j - 1][k] + 1);
                }
            }
            mx[i] = max(mx[i], dp[i][j]);
            rmx[i] = max(rmx[i], rdp[i][j]);
        }
    }

    printDP();

    int ans = max(mx[N - 1], rmx[N - 1]);
    cout << ans << endl;
    for (int i = 1; i < N - 1; i++) {
        ans = max(ans, mx[i - 1] + rmx[N - i - 2]);
        int cand = mx[i - 1] + rmx[N - i - 2];
        cout << i << " " << cand << endl;
        if (ans < cand) {
            ans = cand;
            cout << "FOUND" << endl;
        }
    }
    cout << ans << endl;

    return 0;
}
