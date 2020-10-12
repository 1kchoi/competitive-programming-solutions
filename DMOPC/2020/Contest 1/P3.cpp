// DMOPC '20 Contest 1 P3 - Victor's Algorithm
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
#define NMAX (int)(5e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, A[NMAX], peak = LONG_LONG_MIN, peakpos, ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (peak < A[i]) {
            peak = A[i];
            peakpos = i;
        }
    }
    ll b = A[0];
    for (int i = 1; i < peakpos; i++) {
        if (b > A[i]) {
            ans += b - A[i];
        }
        else {
            b = A[i];
        }
    }
    b = A[N - 1];
    for (int i = N - 2; i > peakpos; i--) {
        if (b > A[i]) {
            ans += b - A[i];
        }
        else {
            b = A[i];
        }
    }
    cout << ans << endl;

    return 0;
}
