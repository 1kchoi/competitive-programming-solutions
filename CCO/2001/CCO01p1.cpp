// CCO '01 P1 - The Monkey Dance
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 110
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct DSU {
    vi e; void init(int N) { e = vi(N, -1); }
    int get(int x) { return (e[x] < 0) ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

int N, A[NMAX], ans;
DSU S;

void resetA() {
    for (int i = 0; i < NMAX; i++) {
        A[i] = 1;
    }
}

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void setIO(string name = "input") {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    setIO();

    while (cin >> N, N) {
        ans = 1;
        resetA();
        S.init(N);
        for (int i = 0; i < N; i++) {
            int a, b; cin >> a >> b; --a; --b;
            S.unite(a, b);
        }
        for (int i = 0; i < N; i++) {
            A[S.get(i)] = S.size(i);
        }
        for (int i = 0; i < N; i++) {
            ans = lcm(ans, A[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
