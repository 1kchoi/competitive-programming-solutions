// DMOPC '14 Contest 3 P5 - Not Enough Servers!
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 20
#define MMAX 50
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, dp[1 << NMAX];
vi B, removeindex, dpbydist[MMAX];
vector<vector<bool>> A;
bool keepers[MMAX];

void binsert(int i) {
    int x = 0;
    for (int j = 0; j < N; j++) {
        if (!A[j][i]) {
            x |= (1 << j);
        }
    }
    B.PB(x);
}

void debugA() {
    cout << "PRINTING A" << endl;
    for (int i = 0; i < sz(A); i++) {
        for (bool x : A[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void debugB() {
    cout << "PRINTING B" << endl;
    for (int x : B) {
        cout << x << endl;
    }
    cout << endl;
}

void debugDPbyDist() {
    cout << "PRINTING DP BY DIST" << endl;
    for (int i = 0; i <= dp[(1 << N) - 1]; i++) {
        cout << i << ": ";
        for (int x : dpbydist[i]) {
            cout << x << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;
    A.assign(N, vector<bool>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c; cin >> c;
            A[i][j] = (c == 'O');
        }
    }
    for (int i = 0; i < N; i++) {
        bool everwrong = false;
        for (int j = 0; j < M; j++) {
            everwrong = everwrong || !A[i][j];
        }
        if (!everwrong) {
            removeindex.PB(i);
        }
    }
    reverse(all(removeindex));
    for (int i : removeindex) {
        A.erase(A.begin() + i);
    }
    N = sz(A);
    if (!N) {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < M; i++) {
        binsert(i);
    }

    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int mask : B) {
        for (int i = (1 << N) - 1; i >= 0; i--) {
            dp[i | mask] = min(dp[i | mask], dp[i] + 1);
        }
    }
    cout << dp[(1 << N) - 1] << endl;

    for (int i = 0; i <= (1 << N) - 1; i++) {
        if (dp[i] <= M) {
            dpbydist[dp[i]].PB(i);
        }
    }

    int goalmask = (1 << N) - 1;
    for (int i = dp[(1 << N) - 1] - 1; i >= 0; i--) {
        bool flag = false;
        for (int mask : dpbydist[i]) {
            for (int j = 0; j < M; j++) {
                if ((mask | B[j]) == goalmask) {
                    if (keepers[j]) continue;
                    keepers[j] = true;
                    flag = true;
                    goalmask = mask;
                    break;
                }
            }
            if (flag) break;
        }
    }

    for (int i = 0; i < M; i++) {
        if (keepers[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
