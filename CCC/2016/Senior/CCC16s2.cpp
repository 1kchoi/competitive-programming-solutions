// CCC '16 S2 - Tandem Bicycle
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x7f7f7f7f
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, Q, ans;
vi A, B;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> Q >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; A.PB(x);
    }
    for (int i = 0; i < N; i++) {
        int x; cin >> x; B.PB(x);
    }
    sort(A.begin(), A.end());
    if (Q == 1) {
        sort(B.begin(), B.end());
    }
    else {
        sort(B.rbegin(), B.rend());
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " " << B[i] << endl;
        ans += max(A[i], B[i]);
    }
    cout << endl << ans << endl;

    return 0;
}
