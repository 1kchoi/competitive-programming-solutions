// Codeforces ####B - Stairs
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T;
ll X;
ll A[1000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> X;

        int lim = 1;
        while (true) {
            ll a = (ll)(pow(2, 2*lim-1) - pow(2, lim-1));
            if (a <= X) {
                A[lim] = a;
                lim++;
            }
            else {
                break;
            }
        }

        //for (int i = 1; i <= lim; i++) {
            //cout << A[i] << " ";
        //}
        //cout << endl;

        ll ans = 0, score = 0;
        for (int i = 1; i < lim; i++) {
            if (score + A[i] <= X) {
                ans++;
                score += A[i];
            }
            else {
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
