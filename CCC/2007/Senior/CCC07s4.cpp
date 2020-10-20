// CCC '07 S4 - Waterpark
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

int N, A[NMAX];
vi G[NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    int a, b;
    while (cin >> a >> b, a && b) {
        G[a].PB(b);
    }
    A[1] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < sz(G[i]); j++) {
            A[G[i][j]] += A[i];
        }
    }

    cout << A[N] << endl;


    return 0;
}
