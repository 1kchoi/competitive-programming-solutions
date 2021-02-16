// Appleby Contest '20 P3 - Ridiculous String
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

ll N, M, reps, pos;
string S, T;
vi A[27];
bool check[27];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M >> S >> T;
    for (int i = 0; i < N; i++) {
        A[S[i] - 'a'].PB(i);
        check[S[i] - 'a'] = true;
    }
    pos = -1;
    for (int i = 0; i < M; i++) {
        int c = T[i] - 'a';
        if (!check[c]) {
            cout << -1 << endl;
            return 0;
        }
        vi::iterator foundit = upper_bound(all(A[c]), pos);
        if (foundit == A[c].end()) {
            pos = -1;
            reps++;
            foundit = upper_bound(all(A[c]), pos);
        }
        pos = *foundit;
    }
    cout << endl;
    cout << reps * N + pos + 1 << endl;

    return 0;
}
