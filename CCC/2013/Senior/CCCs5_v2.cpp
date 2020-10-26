// CCC '13 S5 - Factor Solitaire
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
#define NMAX (int)(5e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, ans;
vi primes;
bool p[NMAX];

void generatePrimes() {
    memset(p, 1, sizeof(p));
    p[0] = p[1] = 0;
    for (int i = 2; i < NMAX; i++) {
        if (p[i]) {
            primes.PB(i);
            for (int j = 2; i * j < NMAX; j++) {
                p[i * j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    generatePrimes();

    cin >> N;

    while (N > 1) { // fix while check
        for (int i = 0; i < sz(primes) && primes[i] <= N; i++) {
            if (!(N % primes[i])) {
                N -= N / primes[i];
                ans += primes[i] - 1;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
