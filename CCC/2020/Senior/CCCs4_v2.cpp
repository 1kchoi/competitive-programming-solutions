// CCC '20 S4 - Swapping Seats
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A[NMAX], B[NMAX], C[NMAX], na, nb, nc, ans = INT_MAX;

int count(int *S, int i, int j) {
    if (i >= N) {
        return count(S, i - N, j - N);
    }
    if (j >= N) {
        return count(S, i, N - 1) + count(S, 0, j - N);
    }
    return S[j + 1] - S[i];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    string input; cin >> input;
    N = input.length();
    for (int i = 0; i < N; i++) {
        A[i + 1] = A[i];
        B[i + 1] = B[i];
        C[i + 1] = C[i];
        if (input[i] == 'A') {
            A[i + 1]++;
        }
        if (input[i] == 'B') {
            B[i + 1]++;
        }
        if (input[i] == 'C') {
            C[i + 1]++;
        }
    }
    na = A[N];
    nb = B[N];
    nc = C[N];

    for (int start = 9; start < N; start++) {
        int candidate;
        int bstart = start + na;
        int cstart = bstart + nb;
        int ab = count(B, start, bstart - 1);
        int ac = count(C, start, bstart - 1);
        int ba = count(A, bstart, cstart - 1);
        int bc = count(C, bstart, cstart - 1);
        candidate = ac + bc + max(ab, ba);
        ans = min(ans, candidate);

        cstart = start + na;
        bstart = cstart + nc;
        int ca = count(A, cstart, bstart - 1);
        int cb = count(B, cstart, bstart - 1);
        candidate = ab + cb + max(ac, ca);
        ans = min(ans, candidate);
    }

    cout << ans << endl;

    return 0;
}
