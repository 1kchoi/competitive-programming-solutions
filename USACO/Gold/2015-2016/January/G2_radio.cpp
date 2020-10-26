// USACO 2016 January Contest, Gold
// Problem 2. Radio Contact
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, M, dp[NMAX][NMAX];
vii A, B;

int dist(ii v, ii u) {
    ll x = v[0] - u[0];
    ll y = v[1] - u[1];
    return x * x + y * y;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    cin >> N >> M;
    ll f, g;
    cin >> f >> g; A.PB({f, g});
    cin >> f >> g; B.PB({f, g});
    string s;
    cin >> s;
    for (int i = 0; i < N; i++) {
        char c = s[i];
        if (c == 'E') {
            A.PB({A[i][0] + 1, A[i][1]});
        }
        if (c == 'W') {
            A.PB({A[i][0] - 1, A[i][1]});
        }
        if (c == 'N') {
            A.PB({A[i][0], A[i][1] + 1});
        }
        if (c == 'S') {
            A.PB({A[i][0], A[i][1] - 1});
        }
    }
    cin >> s;
    for (int i = 0; i < M; i++) {
        char c = s[i];
        if (c == 'E') {
            B.PB({B[i][0] + 1, B[i][1]});
        }
        if (c == 'W') {
            B.PB({B[i][0] - 1, B[i][1]});
        }
        if (c == 'N') {
            B.PB({B[i][0], B[i][1] + 1});
        }
        if (c == 'S') {
            B.PB({B[i][0], B[i][1] - 1});
        }
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            ll c1 = (i) ? dp[i - 1][j] : LLONG_MAX;
            ll c2 = (j) ? dp[i][j - 1] : LLONG_MAX;
            ll c3 = (i && j) ? dp[i - 1][j - 1] : LLONG_MAX;
            if (i || j) dp[i][j] = min({c1, c2, c3}) + dist(A[i], B[j]);
        }
    }

    cout << dp[N][M] << endl;
    cout << INF << endl;

    return 0;
}
