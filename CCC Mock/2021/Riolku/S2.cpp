// Riolku's Mock CCC S2 - Keen Keener Sequence
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1.5e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, A[NMAX], B[NMAX][NMAX], ans;
map<ll, ll> M;

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

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << A[i] * A[j];
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] * A[j] >= 175) {
                cout << i << " " << j << endl;
            }
        }
    }

    for (int i = 0; i + 1 < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll x = A[i] * A[j];
            B[i][j] = x;
            ans += M[x];
            cout << "+" << M[x] << endl;
            M[x]++;
        }
    }
    cout << ans << endl;
    for (int i = 0; i + 1 < N; i++) {
        M.clear();
        for (int j = i + 1; j < N; j++) {
            ll x = B[i][j];
            ans -= M[x];
            M[x]++;
        }
    }
    for (int j = 1; j < N; j++) {
        M.clear();
        for (int i = 0; i < j; i++) {
            ll x = B[i][j];
            ans -= M[x];
            M[x]++;
        }
    }
    cout << ans << " ";
    cout << ans * 8 << endl;


    return 0;
}
