// TEST SET GENERATOR
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

int N, K;
vi A;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".in").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    srand((unsigned) time(0));

    N = 10, K = 4;
    //cout << N << " " << K << endl;
    for (int i = 0; i < N; i++) {
        A.PB(rand() % 50 + 1);
    }
    sort(all(A));
    for (int x : A) {
        cout << x << endl;
    }

    return 0;
}
