// USACO 2017 US Open Contest, Gold
// Problem 1. Bovine Genomics
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 505
#define INF 0x3f
typedef ar<ll, 2> ii;
typedef ar<bool, 2> bb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, ans;
string A[NMAX], B[NMAX];
ll P[NMAX][2];
const ll P0 = 50101, M0 = (ll)(1e6 + 3), M1 = (ll)(1e6 + 159);
ll MOD[2] = {M0, M1};
ll hashA[NMAX][2], hashB[NMAX][2];
bool filter[(int)(1e6 + 200)][2];

void initializeP() {
    P[0][0] = P[0][1] = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 2; j++) {
            P[i][j] = P[i - 1][j] * P0;
            P[i][j] %= MOD[j];
        }
    }
}

bool check(int X) { // USE MULTIPLE HASHES
    memset(hashA, 0 , sizeof(hashA));
    memset(hashB, 0 , sizeof(hashB));
    for (int i = 0; i < M; i++) { // ith character being added
        // add front character
        for (int j = 0; j < N; j++) { // jth string in set A/B
            for (int k = 0; k < 2; k++) { // kth modulo
                hashA[j][k] *= P[1][k];
                hashA[j][k] += A[j][i];
                hashA[j][k] %= MOD[k];

                hashB[j][k] *= P[1][k];
                hashB[j][k] += B[j][i];
                hashB[j][k] %= MOD[k];
            }
        }

        // check for matches, return false if found
        if (i >= X - 1) {
            memset(filter, 0, sizeof(filter));

            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 2; k++) {
                    filter[hashA[j][k]][k] = true;
                }
            }
            bool flag = true;
            for (int j = 0; j < N && flag; j++) {
                if (filter[hashB[j][0]][0] && filter[hashB[j][1]][1]) {
                    flag = false;
                }
            }
            if (flag) {
                return true;
            }

            // removing first char
            for (int j = 0; j < N; j++) { // jth string in set A/B
                for (int k = 0; k < 2; k++) { // kth modulo
                    int f = (A[j][i - X + 1] * P[X - 1][k]) % MOD[k];
                    hashA[j][k] -= f;
                    hashA[j][k] += MOD[k];
                    hashA[j][k] %= MOD[k];
                    f = (B[j][i - X + 1] * P[X - 1][k]) % MOD[k];
                    hashB[j][k] -= f;
                    hashB[j][k] += MOD[k];
                    hashB[j][k] %= MOD[k];

                }
            }
        }
    }
    return false;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("cownomics");

    cin >> N >> M;
    initializeP();
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int l = 1, r = M;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}
