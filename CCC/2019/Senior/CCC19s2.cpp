// CCC '19 S2 - Pretty Average Primes
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N;
bool primes[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(primes, 1, sizeof(primes));
    primes[0] = primes[1] = 0;
    for (int i = 2; i < NMAX; i++) {
        if (primes[i]) {
            for (int j = 2; i * j < NMAX; j++) {
                primes[i * j] = 0;
            }
        }
    }

    cin >> T;
    while (T--) {
        cin >> N;
        N *= 2;
        for (int i = 0; i * i < NMAX; i++) {
            if (primes[i] && primes[N - i]) {
                cout << i << " " << N - i << endl;
                break;
            }
        }
    }

    return 0;
}
