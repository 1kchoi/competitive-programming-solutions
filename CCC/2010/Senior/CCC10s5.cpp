// CCC '10 S5 - Nutrient Tree
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
int X;

vi generateopt(int val) {
    vi ans(X + 2);

    return ans;
}

vi solve(int pos, bool applytax = 1) {
    vi ans(X + 2), optl, optr;
    int i;
    for (i = pos; i < sz(S); i++) {
        if (S[i] == '(') {
            optl = solve(i + 1);
            break;
        }
        if (S[i] >= '0' && S[i] <= '9') {
            int st = i, l = 0;
            while (st + l < sz(S) && S[st + l] >= '0' && S[st + l] <= '9') {
                l++;
            }
            int val = stoi(S.substr(st, l));
            optl = generateopt(val);
            break;
        }
    }
    return ans;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    getline(cin, S);
    cin >> X;
    solve(1, 0);

    return 0;
}
