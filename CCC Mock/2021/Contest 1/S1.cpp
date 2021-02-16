// Mock CCC '21 S1 - Edit Distance
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

vector<char> A;
string S;
set<string> ans;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    string alphabet; cin >> alphabet;
    for (int i = 0; i < sz(alphabet); i++) {
        A.PB(alphabet[i]);
    }
    cin >> S;

    for (int i = 0; i < sz(S); i++) {
        for (int j = 0; j < sz(A); j++) {
            ans.insert(S.substr(0, i) + A[j] + S.substr(i));
            ans.insert(S.substr(0, i) + A[j] + S.substr(i + 1));
        }
    }
    for (int j = 0; j < sz(A); j++) {
        ans.insert(S + A[j]);
        ans.insert(S.substr(0, sz(S) - 1) + A[j]);
    }

    for (int i = 0; i + 1 < sz(S); i++) {
        ans.insert(S.substr(0, i) + S.substr(i + 1));
    }
    ans.insert(S.substr(0, sz(S) - 1));

    for (set<string>::iterator it = ans.begin(); it != ans.end(); it++) {
        if (S.compare(*it)) cout << *it << endl;
    }

    return 0;
}
