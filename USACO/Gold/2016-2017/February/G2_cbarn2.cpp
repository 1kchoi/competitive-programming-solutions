// Codeforces ####A - NAME
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
#define NMAX (int)(1e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K;
ll dp[10][103], ans = LONG_LONG_MAX;
vi A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> K;
    A.assign(N,0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        memset(dp, 0, sizeof(dp));

        for (int k = 2; k <= K; k++) {
            for (int last = 1; last < N; last++) {
                for (int x = k)
            }
        }

        A.PB(A[0]); A.erase(0);
    }

    return 0;
}
