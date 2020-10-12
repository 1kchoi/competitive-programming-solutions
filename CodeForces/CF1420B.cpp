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

int T, N;
vi A;
ll ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        ans = 0;
        A.clear();

        cin >> N;
        for (int i = 0; i < N; i++) {
            int x; cin >> x; A.PB(x);
        }
        sort(all(A));

        int pow = 2, count = 0;
        for (int i = 0; i < N; i++) {
            while (A[i] >= pow) {
                pow *= 2;
                count = 0;
            }
            ans += count++;
        }

        cout << ans << endl;
    }

    return 0;
}
