// USACO 2021 January Contest, Silver
// Problem 1. Dance Mooves
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
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct DSU {
    vi e; void init(int N) {e.assign(N, -1);}
    int get(int i) { return (e[i] < 0) ? i : e[i] = get(e[i]); }
    bool sameSet(int i, int j) { return (get(i) == get(j)); }
    int size(int i) { return -e[get(i)]; }
    bool unite(int i, int j) {
        i = get(i), j = get(j); if (i == j) return 0;
        if (e[i] > e[j]) swap(i, j);
        e[j] += e[i]; e[i] = j; return 1;
    }
};

int N, K, M, cows[NMAX], moves[KMAX][2];
set<int> cowPos[NMAX], ans[NMAX];
DSU S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

void printCowPos() {
    for (int i = 1; i <= N; i++) {
        cout << i << ": ";
        for (int x : cowPos[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printCows() {
    for (int i = 1; i <= N; i++) {
        cout << cows[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> K >> M;
    S.init(N + 1);
    for (int i = 1; i <= N; i++) {
        cows[i] = i;
        cowPos[i].insert(i);
    }
    for (int i = 0; i < K; i++) {
        int a, b; cin >> a >> b;
        moves[i][0] = a; moves[i][1] = b;
        swap(cows[a], cows[b]);
        cowPos[cows[a]].insert(a);
        cowPos[cows[b]].insert(b);
    }

    for (int i = 1; i <= N; i++) {
        S.unite(i, cows[i]);
    }
    for (int i = 1; i <= N; i++) {
        int parent = S.get(i);
        for (int pos : cowPos[i]) {
            ans[parent].insert(pos);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << sz(ans[S.get(i)]) << endl;
    }

    return 0;
}
