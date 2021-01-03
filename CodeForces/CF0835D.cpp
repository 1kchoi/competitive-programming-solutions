// Codeforces 835D. Palindromic characteristics
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(5e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

string S;
int N, ans[NMAX];
ll H[NMAX][NMAX];
const ll P = 9973;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

void solve(int start, int k, int i) {
    if (start + k > N) return;
    if (H[start][start + i / 2 - 1] == H[start + i - i / 2][start - 1]) {
        ans[k]++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> S;
    N = sz(S);

    for (int start = 0; start < N; ++start) {
        ll A = 0;
        for (int i = start; i < N; ++i) {
            A *= P; A %= MOD;
            A += S[i]; A %= MOD;
            H[start][i] = A;
        }
    }

    for (int start = 0; start < N; start++) {
        for (int k = 1; start + 2 * k < N; i++) {
            ans[k] += 
        }
    }

    return 0;
}
