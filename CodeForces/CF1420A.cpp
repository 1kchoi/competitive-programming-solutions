// Codeforces 1420A. Cubes Sorting
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
#define NMAX (int)(2e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N, A[NMAX];
bool can;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> N;
        can = false;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            if (i > 0) {
                if (A[i] >= A[i-1]) {
                    can = true;
                }
            }
        }

        if (can) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO\n";
        }

    }

    return 0;
}
