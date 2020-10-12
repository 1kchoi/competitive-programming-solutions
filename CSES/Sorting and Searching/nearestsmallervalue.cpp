// CSES Problem Set - Nearest Smaller Values
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
vii A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        while (A.size() && x <= A.back()[0]) {
            A.pop_back();
        }
        if (!A.size()) {
            cout << 0 << " ";
        }
        else {
            cout << A.back()[1] << " ";
        }
        A.PB({x, i});
    }
    cout << endl;

    return 0;
}
