// CSES Problem Set - Maximum Subarray Sum II
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A, B;
ll P[NMAX];

set<ii> S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> P[i+1];
        P[i+1] += P[i];
    }

    ll ans = -1e18;
    for (int i = 0; i <= N; i++) {
        if (i-A >= 0) {
            S.insert(ii(P[i-A], i-A));
        }
        if (S.size()) {
            ans = max(ans, P[i] - (*S.begin()).first);
        }
        if (i-B >= 0) {
            S.erase(ii(P[i-B], i-B));
        }
    }
    cout << ans << endl;

    return 0;
}
