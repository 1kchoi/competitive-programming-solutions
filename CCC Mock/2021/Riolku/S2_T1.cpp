// Riolku's Mock CCC S2 - Keen Keener Sequence
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
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, A[55], ans;

bool check(int i, int j, int k, int l) {
    vi b;
    b.PB(i);
    b.PB(j);
    b.PB(k);
    b.PB(l);
    sort(all(b));
    return (b[0] != b[1] && b[1] != b[2] && b[2] != b[3]);
}

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
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    if (A[i] * A[j] == A[k] * A[l]) {
                        if (check(i, j, k, l)) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
