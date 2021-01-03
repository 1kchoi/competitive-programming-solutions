// USACO 2016 February Contest, Gold
// Problem 3. Fenced In
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 2010
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll AMX, BMX, N, M;
vector<ar<ll, 3>> G;
vector<ll> A, B;

int c(int i, int j) {
    return j * (N + 2) + i;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> AMX >> BMX >> N >> M;
    A.assign(N + 2, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    A[N + 1] = AMX;
    sort(all(A));

    B.assign(M + 2, 0);
    for (int i = 0; i <= M; i++) {
        cin >> B[i];
    }
    B[M + 1] = BMX;
    sort(all(B));

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            G.PB({j * (N + 2) + i, i * N + 2) + j + 1})
        }
    }

    return 0;
}
