// CSES Problem Set - Money Sums
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 105
#define KMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A[NMAX], X;
bool dp[KMAX];
vi ans;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int j = KMAX - 1; j >= A[i]; j--) {
            dp[j] |= dp[j - A[i]];
        }
    }
    for (int i = 1; i < KMAX; i++) {
        if (dp[i]) {
            X++;
            ans.PB(i);
        }
    }
    cout << X << endl;
    for (int v : ans) {
        cout << v << " ";
    }
    cout << endl;


    return 0;
}
