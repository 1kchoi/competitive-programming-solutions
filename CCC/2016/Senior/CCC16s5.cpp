// CCC '16 S5 - Circle of Life
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
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, T;
vi seq;
bool dp[55][NMAX];

int countmag(ll X) {
    int ans = 0;
    while (X) {
        ans++;
        X /= 2;
    }
    return ans - 1;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        dp[0][i] = (c == '1');
    }
    //ll test = 1e15;
    //cout << bitset<64>(test) << " " << countmag(test) << endl;

    while (T) {
        seq.PB(T);
        T ^= (1LL << countmag(T));
    }
    seq.PB(0);
    reverse(all(seq));

    for (int i = 1; i < sz(seq); i++) {
        ll x = seq[i];
        ll l = countmag(x);
        ll d = (1LL << l) % N;
        for (int j = 0; j < N; j++) {
            ll a = (j + d) % N;
            ll b = (j - d + N) % N;
            dp[i][j] = dp[i - 1][a] ^ dp[i - 1][b];
            if (i == sz(seq) - 1) cout << dp[i][j];
        }
    }
    cout << endl;
    //*/

    return 0;
}
