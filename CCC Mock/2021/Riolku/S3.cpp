// Riolku's Mock CCC S3 - Mosey's Birthday
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, A[NMAX], degree[NMAX], K, codenames[NMAX];
vii G[NMAX], EL;
bool discovered[NMAX], discovered2[NMAX], blockednode[NMAX];
vi placeinround, personinround, path, anspath;

bool articdiscov[NMAX];

void dfs1(int node) {
    discovered[node] = true;
    placeinround.PB(node);
    personinround.PB(A[node]);
    for (ii u : G[node]) {
        if (!discovered[u[0]]) {
            dfs1(u[0]);
        }
    }
}



bool dfs2(int node) {

}

void articdfs(int node, int banned) {
    articdiscov[node] = true;
    for (ii e : G[node]) {
        if (blockednode[e[0]]) continue;
        if (articdiscov[e[0]]) continue;
        if (e[0] == banned) continue;
        articdfs(e[0], banned);
    }
}

bool isArticulationPoint(int node, int banned) {
    memset(articdiscov, 0, sizeof(articdiscov));
    articdfs(node, banned);
    for (int v : placeinround) {
        if (!articdiscov[v] && v != banned) return true;
    }
    return false;
}

void bring(int st, int en) {
    memset(discovered2, 0, sizeof(discovered2));
}

void process(int node) {
    placeinround.clear();
    personinround.clear();
    dfs1(node);
    sort(all(placeinround));
    sort(all(personinround));
    for (int i = 0; i < sz(placeinround); i++) {
        codenames[placeinround[i]] = personinround[i];
    }
    while (sz(placeinround)) {
        for (int i = 0; i < sz(placeinround); i++) {
            int place = placeinround[i];
            if (!isArticulationPoint(place)) {
                bring()
                break;
            }
        }
    }
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
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        EL.PB({u, v});
        G[u].PB({v, i});
        G[v].PB({u, i});
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= N; i++) {
        if (!discovered[i]) {
            process(i);
        }
    }

    return 0;
}
