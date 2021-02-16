// USACO 2016 February Contest, Gold
// Problem 3. Fenced In
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct DSU {
    int e[NMAX][NMAX][2];
    void init() { memset(e, -1, sizeof(e)); }
    ii get(int i, int j) {
        if (e[i][j][0] < 0) {
            return {i, j};
        }
        ii ans = get(e[i][j][0], e[i][j][1]);
        e[i][j][0] = ans[0];
        e[i][j][1] = ans[1];
        return ans;
    }
    bool isSameSet(int i1, int j1, int i2, int j2) { return get(i1, j1) == get(i2, j2); }
    int size(int i, int j) {
        ii parent = get(i, j);
        return -e[parent[0]][parent[1]][0];
    }
    bool unite(int i1, int j1, int i2, int j2) {
        ii parent1 = get(i1, j1), parent2 = get(i2, j2);
        if (parent1 == parent2) return false;
        i1 = parent1[0]; j1 = parent1[1]; i2 = parent2[0]; j2 = parent2[1];
        if (size(i1, j1) > size(i2, j2)) {
            swap(i1, i2); swap(j1, j2);
        }
        e[i1][j1][0] += e[i2][j2][0];
        e[i1][j1][1] = e[i1][j1][0];
        e[i2][j2][0] = i1; e[i2][j2][1] = j1;
        return true;
    }
};

int A, B, N, M;
ll ans;
vi hor, vert;
DSU S;
vector<ar<int, 5>> EL;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("fencedin");

    cin >> A >> B >> N >> M;
    S.init();
    for (int i = 0; i < N; i++) {
        int x; cin >> x; hor.PB(x);
    }
    for (int i = 0; i < M; i++) {
        int x; cin >> x; vert.PB(x);
    }
    hor.PB(A); hor.PB(0); vert.PB(B); vert.PB(0);
    sort(all(vert)); sort(all(hor));
    for (int i = 0; i <= N; i++) {
        int weight = hor[i + 1] - hor[i];
        for (int j = 0; j + 1 <= M; j++) {
            EL.PB({weight, i, j, i, j + 1});
        }
    }
    for (int i = 0; i <= M; i++) {
        int weight = vert[i + 1] - vert[i];
        for (int j = 0; j + 1 <= N; j++) {
            EL.PB({weight, j, i, j + 1, i});
        }
    }
    sort(all(EL));
    for (ar<int, 5> e : EL) {
        int weight = e[0];
        int i1 = e[1], j1 = e[2], i2 = e[3], j2 = e[4];
        if (S.unite(i1, j1, i2, j2)) {
            ans += weight;
        }
    }
    cout << ans << endl;

    return 0;
}
