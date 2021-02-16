// CCC '19 S4 - Tourism
// correct on CCC grader, but incorrect on DMOJ
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define LOGNMAX 30
#define INF 0x3f3f3f
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

template<class T> struct RMQ {
    T A[NMAX], SpT[LOGNMAX][NMAX];
    void init(int n, T *input) {
        for (int i = 0; i < n; i++) {
            A[i] = input[i];
            SpT[0][i] = i;
        }
        for (int i = 1; (1<<i) <= n; i++) {
            for (int j = 0; j + (1<<i) - 1 < n; j++) {
                if (A[ SpT[i-1][j] ] > A[ SpT[i-1][j+(1<<(i-1))] ]) {
                    SpT[i][j] = SpT[i-1][j];
                }
                else {
                    SpT[i][j] = SpT[i-1][j+(1<<(i-1))];
                }
            }
        }
    }

    T query(int a, int b) {
        int level = (int)floor(log((double)(b-a+1)) / log(2.0));
        /*
        if (A[SpT[level][a]] > A[SpT[level][b - (1<<level) + 1]]) {
            return SpT[level][a];
        }
        else {
            return SpT[level][b - (1<<level) + 1];
        }
        */
        if (a>b) return INT_MIN;
        return max(A[SpT[level][a]], A[SpT[level][b - (1<<level) + 1]]);
    }

    void printArray(int n) {
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl << endl;
        for (int i = 0; (1<<i) <= n; i++) {
            for (int j = 0; j + (1<<i) - 1 < n; j++) {
                cout << SpT[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

ll N, K, p, A[NMAX], idx[NMAX], dp[NMAX];
RMQ<ll> M;

void printDP() {
    for (int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        idx[i+1] = i/K + 1;
    }

    M.init(N, A);

    for (int i = 1; i <= N; i++) {
        if (idx[i] != idx[i-1]) {
            p = max(i-K, 0LL);
        }
        p = max(p, i-K);

        dp[i] = dp[p] + M.query(p, i-1);

        while (idx[p] == idx[p+1] && dp[i] <= dp[p+1] + M.query(p+1, i-1)) {
            p++;
            dp[i] = dp[p] + M.query(p, i-1);
        }
    }

    printDP();
    cout << dp[N] << endl;


    return 0;
}
