// CSES Problem Set - Two Sets
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N;
vi A;
bool found[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    if ((N * (N + 1) / 2) % 2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    ll sum = 0;
    ll threshold =  N * (N + 1) / 4;
    for (int i = N; i >= 0 && sum <= threshold; i--) {
        if (sum + i >= threshold) break;
        sum += i;
        A.PB(i);
        found[i] = true;
    }
    ll missing = N * (N + 1) / 4 - sum;
    A.PB(missing);
    found[missing] = true;

    cout << sz(A) << endl;
    for (ll x : A) {
        cout << x << " ";
    }
    cout << endl;
    cout << N - sz(A) << endl;
    for (int i = 1; i <= N; i++) {
        if (!found[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}
