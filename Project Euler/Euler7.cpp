// Problem 7 - 10001st prime[]
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e7+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

bool isPrime[NMAX];
vector<ll> primes;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i < NMAX; i++) {
        if (isPrime[i]) {
            primes.PB(i);
            for (int j = 2; i * j < NMAX; j++) {
                isPrime[i * j] = 0;
            }
        }
    }
    cout << primes[10000] << endl;

    return 0;
}
