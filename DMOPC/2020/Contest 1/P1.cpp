// DMOPC '20 Contest 1 P1 - Victor Gets Quizzed
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
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
string S;
bool math, compsci;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        math = compsci = false;
        for (int j = 0; j < sz(S); j++) {
            if (S[j] == 'M') {
                math = true;
            }
            if (S[j] == 'C') {
                compsci = true;
            }
        }
        if (math && compsci) {
            cout << "NEGATIVE MARKS" << endl;
        }
        else if (math || compsci) {
            cout << "FAIL" << endl;
        }
        else {
            cout << "PASS" << endl;
        }
    }

    return 0;
}
