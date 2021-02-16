// CSES Problem Set - Palindrome Reorder
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

string S;
int freq[260];
int odd = -1;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> S;
    for (int i = 0; i < sz(S); i++) {
        freq[(int)S[i]]++;
    }
    for (int i = 0; i < 260; i++) {
        if (freq[i] % 2) {
            if (odd != -1) {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            odd = i;
        }
    }
    for (int i = 0; i < 260; i++) {
        if (i != odd) {
            for (int j = 0; j < freq[i] / 2; j++) {
                cout << (char)(i);
            }
        }
    }
    for (int j = 0; j < freq[odd]; j++) {
        cout << (char)(odd);
    }
    for (int i = 259; i >= 0; i--) {
        if (i != odd) {
            for (int j = 0; j < freq[i] / 2; j++) {
                cout << (char)(i);
            }
        }
    }
    cout << endl;

    return 0;
}
