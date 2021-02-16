// DMOPC '15 Contest 1 P5 - Lelei and Dragon Scales
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 255
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, X, A[NMAX][NMAX];

int sum(int i1, int j1, int i2, int j2) {
    return A[i2][j2] - A[i1 - 1][j2] - A[i2][j1 - 1] + A[i1 - 1][j1 - 1];
}

int solve1() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = i; k <= N; k++) {
                for (int l = j; l <= M; l++) {
                    if ((k - i + 1) * (l - j + 1) <= X) {
                        ans = max(ans, sum(i, j, k, l));
                    }
                }
            }
        }
    }
    return ans;
}

int solve2() {
    int ans = 0;
    for (int x = 1; (x - 1) * (x - 1) <= X; x++) {
        int l = x, w = X / x;
        //cout << "NOW AT " << l << " " << w << endl;
        for (int i = 1; i + l - 1 <= N; i++) {
            for (int j = 1; j + w - 1 <= M; j++) {
                int s = sum(i, j, i + l - 1, j + w - 1);
                ans = max(ans, s);
                //cout << i << " " << j << " " << i + l - 1 << " " << j + w - 1 << ": " << s << endl;
            }
        }
        for (int i = 1; i + w - 1 <= N; i++) {
            for (int j = 1; j + l - 1 <= M; j++) {
                int s = sum(i, j, i + w - 1, j + l - 1);
                ans = max(ans, s);
                //cout << i << " " << j << " " << i + w - 1 << " " << j + l - 1 << ": " << s << endl;
            }
        }
    }
    return ans;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> M >> N >> X;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        }
    }
    //cout << solve1() << " ";
    cout << solve2() << endl;

    return 0;
}
