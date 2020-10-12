// Google Kick Start 2020 Round F Question 2 - Metal Harvest
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

int T, N, K, ans;
vii A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        A.clear(); ans = 0;

        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            int a, b; cin >> a >> b;
            A.PB(ii(a,b));
        }
        sort(A.begin(), A.end());

        int start = -1, end = -1;
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                start = A[i].first, end = start + K;
                ans++;
            }

            while (end < A[i].second) {
                ans++;
                start = max(end, A[i].first);
                end = start + K;
            }
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}
