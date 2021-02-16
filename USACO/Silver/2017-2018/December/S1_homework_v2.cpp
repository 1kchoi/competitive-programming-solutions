// USACO 2017 December Contest, Silver
// Problem 1. My Cow Ate My Homework
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
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, A[NMAX], psum[NMAX], smallestScore, avgn = NMAX, avgsum;
vi ans;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("homework");

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        psum[i + 1] = psum[i] + A[i];
    }
    smallestScore = A[N - 1];
    for (int i = N - 1; i > 1; i--) {
        smallestScore = min(smallestScore, A[i]);
        ll currentsum = psum[N] - psum[i - 1] - smallestScore;
        ll currentn = N - i;
        if (avgsum * currentn == currentsum * avgn) {
            ans.PB(i - 1);
        }
        if (avgsum * currentn < currentsum * avgn) {
            avgsum = currentsum;
            avgn = currentn;
            ans.clear();
            ans.PB(i - 1);
        }
    }
    reverse(all(ans));
    for (ll x : ans) {
        cout << x << endl;
    }

    return 0;
}
