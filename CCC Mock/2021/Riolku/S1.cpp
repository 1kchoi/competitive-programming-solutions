// Riolku's Mock CCC S1 - Word Bot
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

int N, C, V, cc, vc;
char vowels[] = {'a', 'e', 'i', 'o', 'u'};
string S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> C >> V >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'y') {
            cc++;
            vc++;
        }
        else {
            bool isvowel = false;
            for (int j = 0; j < 5; j++) {
                if (S[i] == vowels[j]) {
                    vc++;
                    cc = 0;
                    isvowel = true;
                    break;
                }
            }
            if (!isvowel) {
                cc++;
                vc = 0;
            }
        }
        if (cc > C || vc > V) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
