// Wesley's Anger Contest 6 Problem 2 - Cheap Christmas Lights
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, B[NMAX], ans;
bool A[NMAX];

bool check(int X) {
    vector<bool> C(A, A + N + 1);
    for (int i = 1; i <= min(X, M); i++) {
        C[B[i]] = !C[B[i]];
    }
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (C[i]) count++;
    }
    return count <= X;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
    }

    int l = 0, r = N;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
