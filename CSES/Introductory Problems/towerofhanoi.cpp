// CSES Problem Set - Tower of Hanoi
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

int N;

void solve(int x, int current, int goal) {
    int helper = 6 - current - goal;
    if (x == 1) {
        cout << current << " " << goal << endl;
        return;
    }
    solve(x - 1, current, helper);
    cout << current << " " << goal << endl;
    solve(x - 1, helper, goal);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    cout << (1 << N) - 1 << endl;
    solve(N, 1, 3);

    return 0;
}
