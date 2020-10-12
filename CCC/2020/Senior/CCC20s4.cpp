// CCC '20 S4 - Swapping Seats
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
#define NMAX (int)(1e6+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

string S;
int N, ans = INT_MAX, countA, countB, countC, A[NMAX], B[NMAX], C[NMAX];

int getSum(int *Q, int start, int length, bool p = false) {
    if (start + length > N) {
        if (p) cout << Q[N-1] << " - " << Q[start-1] << " + " << Q[(start + length - 1) % N] << endl;
        return Q[N-1] - Q[start-1] + Q[(start + length - 1) % N];
    }
    if (!start) return Q[start+length-1];
    return Q[start+length-1] - Q[start-1];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> S;
    N = sz(S);
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            A[i] = A[i-1];
            B[i] = B[i-1];
            C[i] = C[i-1];
        }
        if (S[i] == 'A') ++A[i];
        if (S[i] == 'B') ++B[i];
        if (S[i] == 'C') ++C[i];
    }
    countA = A[N-1];
    countB = B[N-1];
    countC = C[N-1];

    for (int i = 0; i < N; i++) {
        int bina = getSum(B, i, countA);
        int cina = getSum(C, i, countA);
        int ainb = getSum(A, (i+countA)%N, countB);

        int na = bina + cina;
        int nb = ainb + getSum(C, (i+countA)%N, countB); // ainb + cinb

        int score = na + nb - min(bina, ainb);
        ans = min(ans, score);

        int ainc = getSum(A, (i+countA)%N, countC);
        int nc = ainc + getSum(B, (i+countA)%N, countC); // ainc + binc

        score = na + nc - min(cina, ainc);
        ans = min(ans, score);
    }

    cout << ans << endl;

    return 0;
}
