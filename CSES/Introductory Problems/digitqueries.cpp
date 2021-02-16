// CSES Problem Set - Digit Queries
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

int Q;
ll N;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> Q;
    while (Q--) {
        cin >> N;
        int mult = 1, k = 1, sum = 0;
        for (; k <= 20; k++, mult *= 10) {
            if (N <= sum + 9 * k * mult) {
                break;
            }
            sum += 9 * k * mult;
        }
        N -= sum;
        while (k > 1) {
            
            k--;
        }
    }

    return 0;
}
