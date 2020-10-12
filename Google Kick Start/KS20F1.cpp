// Google Kick Start 2020 Round F Question 1 - ATM Queue
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
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N, X;
set<ii> A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        A.clear();
        cout << "Case #" << tc << ": ";

        cin >> N >> X;
        for (int i = 1; i <= N; i++) {
            int p; cin >> p;
            A.insert(ii((p-1)/X, i));
        }

        for (auto& it : A) {
            cout << it.second << " ";
        }
        cout << endl;
    }

    return 0;
}
