// USACO 2021 January Contest, Gold
// Problem 3. Dance Mooves
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define KMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct DSU {
    vi e; void init(int N) {e.assign(N, -1);}
    ll get(ll i) { return (e[i] < 0) ? i : e[i] = get(e[i]); }
    bool sameSet(int i, int j) { return (get(i) == get(j)); }
    ll size(int i) { return -e[get(i)]; }
    bool unite(int i, int j) {
        i = get(i), j = get(j); if (i == j) return 0;
        if (e[i] > e[j]) swap(i, j);
        e[j] += e[i]; e[i] = j; return 1;
    }
};

ll N, K, M, cows[NMAX], moves[KMAX][2], maxcycle, reps;
set<ll> cowPos[NMAX], ans[NMAX];
DSU S;

void printAns1() {
    for (int i = 1; i <= N; i++) {
        cout << sz(cowPos[i]) << endl;
    }
}

void printAns2() {
    for (int i = 1; i <= N; i++) {
        int parent = S.get(i);
        for (int pos : cowPos[i]) {
            ans[parent].insert(pos);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << sz(ans[S.get(i)]) << endl;
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> K >> M;
    for (int i = 1; i <= N; i++) {
        cows[i] = i;
        cowPos[i].insert(i);
    }
    for (int i = 0; i < min(K, M); i++) {
        int a, b; cin >> a >> b;
        moves[i][0] = a; moves[i][1] = b;
        swap(cows[a], cows[b]);
        cowPos[cows[a]].insert(a);
        cowPos[cows[b]].insert(b);
    }

    if (M <= K) {
        printAns1();
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        S.unite(i, cows[i]);
        maxcycle = max(maxcycle, S.size(i));
    }
    if (K * maxcycle <= M) {
        printAns2();
        return 0;
    }

    reps = (M - K) / K;

    while (reps) {
        if (reps & 1) {
            
        }
        reps /= 2;
    }

    return 0;
}
