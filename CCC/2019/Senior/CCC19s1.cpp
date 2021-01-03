// CCC '19 S1 - Flipper
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

string S;
int N;
bool H, V;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> S;
    N = sz(S);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'H') {
            H = !H;
        }
        if (S[i] == 'V') {
            V = !V;
        }
    }
    if (!H && !V) {
        cout << "1 2" << endl;
        cout << "3 4" << endl;
    }
    if (H && !V) {
        cout << "3 4" << endl;
        cout << "1 2" << endl;
    }
    if (!H && V) {
        cout << "2 1" << endl;
        cout << "4 3" << endl;
    }
    if (H && V) {
        cout << "4 3" << endl;
        cout << "2 1" << endl;
    }

    return 0;
}
