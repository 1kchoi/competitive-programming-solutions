// Appleby Contest '20 P1 - Terrific Triangles
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

ll N, A[3];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    while (N--) {
        cin >> A[0] >> A[1] >> A[2];
        sort(A, A + 3);
        ll sum = A[0] * A[0] + A[1] * A[1];
        ll sum2 = A[2] * A[2];
        if (sum == sum2) {
            cout << "R" << endl;
        }
        else if (sum < sum2) {
            cout << "O" << endl;
        }
        else {
            cout << "A" << endl;
        }
    }

    return 0;
}
