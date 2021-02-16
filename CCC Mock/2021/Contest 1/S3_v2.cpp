// Mock CCC '21 S3 - Lexicographically Smallest Permutation Subsequence
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K, A[NMAX], D[NMAX];
set<int> S;
vi ans;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        S.insert(A[i]);
        D[i] = sz(S);
    }
    int m = A[0];
    for (int i = 1; i < N; i++) {
        if (D[i] != D[i - 1]) {
            ans.PB(m);
            m = A[i];
        }
        else {
            m = min(m, A[i]);
        }
    }
    ans.PB(m);

    for (int i = 0; i < sz(ans); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;


    return 0;
}
