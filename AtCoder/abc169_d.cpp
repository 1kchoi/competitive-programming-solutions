// AtCoder Beginner Contest 169 D - Div Game
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define PMAX (int)(1e7+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, ans;
bool p[PMAX];
vector<ll> primes;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;

    memset(p, 1, sizeof(p));
    p[0] = p[1] = 0;
    for (int i = 2; i < PMAX; i++) {
        if (p[i]) {
            primes.PB(i);
            for (int j = 2; i * j < PMAX; j++) {
                p[i * j] = 0;
            }
        }
    }

    for (int i = 0; i < sz(primes) && N > 1; i++) {
        int x = 0, points = 0;
        while (N % primes[i] == 0) {
            N /= primes[i];
            if (++x > points) {
                ++points;
                x = 0;
            }
        }
        ans += points;
    }

    cout << ans + (N > PMAX) << endl;

    return 0;
}
