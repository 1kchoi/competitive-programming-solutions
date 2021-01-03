// CCC '20 J4 - Cyclic Shifts
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

string T, S;
int N, M;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> T >> S;
    N = sz(T);
    M = sz(S);
    for (int i = 0; i < M; i++) {
        if ((int)(T.find(S)) != -1) {
            cout << "yes" << endl;
            return 0;
        }
        S = S.substr(1) + S[0];
    }
    cout << "no" << endl;

    return 0;
}
