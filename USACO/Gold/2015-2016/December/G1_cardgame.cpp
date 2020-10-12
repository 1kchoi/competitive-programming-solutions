// USACO 2015 December Contest, Gold
// Problem 1. High Card Low Card (Gold)
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
#define NMAX (int)(5e4+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, ans;
bool elsie[2*NMAX];
vi B1, B2, E1, E2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("cardgame.in", "r", stdin);
    //freopen("input.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        elsie[x] = true;
        if (sz(E1) < N/2) {
            E1.PB(x);
        }
        else {
            E2.PB(x);
        }
    }

    for (int i = 1; i <= 2 * N; i++) {
        if (!elsie[i]) {
            if (sz(B2) < N/2) {
                B2.PB(i);
            }
            else {
                B1.PB(i);
            }
        }
    }

    sort(E1.begin(), E1.end());
    sort(E2.rbegin(), E2.rend());
    sort(B2.rbegin(), B2.rend());

    for (int i = 0, j = 0; i < N/2 && j < N/2; i++, j++) { // i is elsie, j is bessie (E[i], B[j])
        while (j < N/2 && E1[i] > B1[j]) {
            j++;
        }
        if (j < N/2) {
            ans++;
        }
    }
    for (int i = 0, j = 0; i < N/2 && j < N/2; i++, j++) { // i is elsie, j is bessie (E[i], B[j])
        while (j < N/2 && E2[i] < B2[j]) {
            j++;
        }
        if (j < N/2) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
