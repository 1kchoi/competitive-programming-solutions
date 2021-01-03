// CCC '19 S4 - Tourism
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define LOGNMAX 30
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

template<class T> struct SparseTable {
    int N;
    T A[NMAX], S[LOGNMAX][NMAX];

    T comb(T x, T y) { return max(x, y); }

    void init(int _N, T *_A) {
        N = _N;
        for (int i = 0; i < _N; i++) {
            A[i] = S[0][i] = _A[i];
        }
        for (int i = 1; (1 << i) <= N; i++) {
            for (int j = 0; j + (1 << i) - 1 < N; j++) {
                S[i][j] = comb(S[i - 1][j], S[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int a, int b) {
        int level = (int)floor(log((double)(b - a + 1)) / log(2.0));
        return comb(S[level][a], S[level][b - (1 << level) + 1]);
    }

};

ll N, K, A[NMAX], dp[NMAX];
SparseTable<ll> RMQ;

void solve(ll l, ll r, ll optl, ll optr) {
    if (l > r) return;
    ll mid = (l + r) >> 1;
    ii best = {-LLONG_MAX/10, -1LL};

    for (ll i = max(mid - K, optl); i <= optr; i++) { // roof = l - 1 on first recursion
        best = max(best, {dp[i] + RMQ.query(i + 1, mid), i});
    }

    dp[mid] = best[0];
    ll opt = best[1];

    solve(l, mid - 1, optl, opt);
    solve(mid + 1, r, opt, optr);
}

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    RMQ.init(N + 1, A);

    for (int i = 1; i <= K; i++) {
        dp[i] = RMQ.query(1, i);
    }

    for (int i = K + 1; i <= N; i += K) {
        solve(i, min(N, i + K - 1), i - K, i - 1);
    }

/*
    for (int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
*/

    cout << dp[N] << endl;


    return 0;
}
