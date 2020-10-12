// Codeforces ####A - Killjoy
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
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

int T, N, X, sum;
bool flag, once;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        sum = 0;
        flag = true;
        once = false;
        cin >> N >> X;
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            sum += a;
            once = once || (a==X);
            flag = flag && (a==X);
        }
        if (flag) {
            cout << 0 << endl;
        }
        else if (once || sum == N*X) {
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
    }

    return 0;
}
