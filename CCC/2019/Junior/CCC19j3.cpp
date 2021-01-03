// CCC '19 J3 - Cold Compress
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

int N;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    while (N--) {
        string S; cin >> S;
        char C = S[0];
        int X = 1;
        for (int i = 1; i < sz(S); i++, X++) {
            if (S[i] != C) {
                cout << X << " " << C << " ";
                C = S[i];
                X = 0;
            }
        }
        cout << X << " " << C << " ";
        cout << endl;
    }

    return 0;
}
