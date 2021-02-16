// Mock CCC '20 Contest 2 S4 - Rotational Arrays
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, A[NMAX], ans = LLONG_MAX;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int k = 1; k < N; k++) {
        if (N % k) continue;
        ll cand = 0;
        for (int start = 0; start < k; start++) {
            vi nums;
            for (int i = start; i < N; i += k) {
                nums.PB(A[i]);
            }
            sort(all(nums));
            ll median = nums[(N / k) / 2];
            for (ll x : nums) {
                cand += abs(x - median);
            }
        }
        ans = min(ans, cand);
    }
    cout << ans << endl;

    return 0;
}
