// CCC '11 S3 - Alice Through the Looking Glass
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

int T, N;
ll A, B;

int check(int M, ll X, ll Y) {
    ll unit = pow(5.0, M - 1.0);
    ll x2 = X/unit, y2 = Y/unit;
    if (y2 == 0) {
        if (x2 == 1 || x2 == 2 || x2 == 3) {
            return 2;
        }
    }
    if (y2 == 1) {
        if (x2 == 2) {
            return 2;
        }
        if (x2 == 1 || x2 == 3) {
            return 1;
        }
    }
    if (y2 == 2) {
        if (x2 == 2) return 1;
    }
    return 0;
}

bool solve(int M, ll X, ll Y) {
    ll unit = pow(5.0, M - 1.0);
    int ans = check(M, X, Y);
    if (ans == 0) {
        return false;
    }
    if (ans == 1) {
        if (M == 1) {
            return false;
        }
        return solve(M-1, X%unit, Y%unit);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> N >> A >> B;
        if (solve(N,A,B)) {
            cout << "crystal" << endl;
        }
        else {
            cout << "empty" << endl;
        }
    }

    return 0;
}
