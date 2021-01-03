// CCO '15 P1 - Hungry Fox
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

int N, pos;
ll W, ans1, ans2;
vector<ll> A;
vi order1, order2;

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x; A.PB(x);
    }
    sort(all(A));
    cout << max(W, A[N - 1]) - min(W, A[0]) << " ";

    for (int i = 0; 2 * i < N; i++) {
        order1.PB(i);
        order2.PB(N - 1 - i);
        if (N % 2 && i == N / 2) continue;
        order1.PB(N - 1 - i);
        order2.PB(i);
    }

    ans1 = abs(W - A[0]);
    ans2 = abs(W - A[N - 1]);
    for (int i = 1; i < N; i++) {
        ans1 += max(abs(W - A[order1[i]]), abs(A[order1[i - 1]] - A[order1[i]]));
        ans2 += max(abs(W - A[order2[i]]), abs(A[order2[i - 1]] - A[order2[i]]));
    }

    cout << max(ans1, ans2) << endl;

    return 0;
}
