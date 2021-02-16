// CCC '14 S4 - Tinted Glass Window
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, T, grid[NMAX][NMAX], ans;
vector<ar<ll, 5>> A; // x1, y1, x2, y2, tint
set<ar<ll, 2>> xset, yset;
vii X, Y;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

void printGrid() {
    cout << setw(3) << "";
    for (int i = 0; i < sz(X); i++) {
        cout << setw(3) << X[i][0];
    }
    cout << endl;
    for (int i = 0; i < sz(Y); i++) {
        cout << setw(3) << Y[i][0];
        for (int j = 0; j < sz(X); j++) {
            cout << setw(3) << grid[j][i];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> T;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3] >> A[i][4];
        xset.insert({A[i][0], i}); xset.insert({A[i][2], i});
        yset.insert({A[i][1], i}); yset.insert({A[i][3], i});
    }
    X.resize(sz(xset)); copy(all(xset), X.begin());
    Y.resize(sz(yset)); copy(all(yset), Y.begin());
    /*
    for (int i = 0; i < sz(X); i++) {
        cout << i << " " << X[i][0] << " " << X[i][1] << endl;
    }
    cout << endl;
    for (int i = 0; i < sz(Y); i++) {
        cout << i << " " << Y[i][0] << " " << Y[i][1] << endl;
    }
    cout << endl;
    */
    for (int i = 0; i < N; i++) {
        ll x1 = lower_bound(all(X), ii({A[i][0], i})) - X.begin();
        ll y1 = lower_bound(all(Y), ii({A[i][1], i})) - Y.begin();
        ll x2 = lower_bound(all(X), ii({A[i][2], i})) - X.begin();
        ll y2 = lower_bound(all(Y), ii({A[i][3], i})) - Y.begin();
        ll tint = A[i][4];
        /*
        cout << "i = " << i << endl;
        cout << A[i][0] << " " << x1 << endl;
        cout << A[i][1] << " " << y1 << endl;
        cout << A[i][2] << " " << x2 << endl;
        cout << A[i][3] << " " << y2 << endl;
        cout << endl;
        */
        assert(x1 >= 0 && y1 >= 0 && x1 < NMAX && y1 < NMAX && x2 < NMAX && y2 < NMAX);
        for (int j = x1; j < x2; j++) {
            grid[j][y1] += tint;
            grid[j][y2] -= tint;
        }
        //printGrid();
    }

    for (int i = 0; i + 1 < sz(X); i++) {
        ll sum = 0;
        for (int j = 0; j + 1 < sz(Y); j++) {
            sum += grid[i][j];
            if (sum >= T) {
                ll rectsize = (X[i + 1][0] - X[i][0]) * (Y[j + 1][0] - Y[j][0]);
                ans += rectsize;
                //cout << "added " << rectsize << " at " << i << " " << j << endl;
                //cout << X[i + 1][0] << " " << X[i][0] << " " << Y[j + 1][0] << " " << Y[j][0] << endl;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
