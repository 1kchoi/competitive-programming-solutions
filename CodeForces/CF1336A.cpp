// Codeforces 1336A. Linova and Kingdom
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(2e5+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K, S[NMAX], D[NMAX], degree[NMAX]; // size and depth
bool discovered[NMAX], industry[NMAX];
vi A, AL[NMAX];
ll ans;

void printAL() {
    for (int i = 0; i < N; i++) {
        cout << i << ": ";
        for (int j = 0; j < degree[i]; j++) {
            cout << AL[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printS() {
    for (int i = 0; i < N; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}

bool mySort(int a, int b) {
    return (S[a]-D[a] < S[b]-D[b]);
}

int dfs(int v) {
    discovered[v] = 1;
    S[v] = 0;
    for (int i = 0; i < degree[v]; i++) {
        int u = AL[v][i];
        if (!discovered[u]) {
            D[u] = D[v] + 1;
            S[v] += dfs(u) + 1;
        }
    }
    return S[v];
}

int dfs2(int v) {
    discovered[v] = 1;
    int mult = industry[v];
    for (int i = 0; i < degree[v]; i++) {
        int u = AL[v][i];
        if (!discovered[u]) {
            mult += dfs2(u);
        }
    }
    if (!industry[v]) {
        ans += mult;
    }
    return mult;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N-1; i++) {
        int v,u;
        cin >> v >> u;
        --v; --u;
        AL[v].PB(u);
        AL[u].PB(v);
        degree[v]++;
        degree[u]++;
    }

    dfs(0);
    memset(discovered, 0, sizeof(discovered));

    for (int i = 0; i < N; i++) {
        A.PB(i);
    }
    sort(A.begin(), A.end(), mySort);

    for (int i = 0; i < K; i++) {
        industry[A[i]] = 1;
    }

    dfs2(0);

    cout << ans << endl;

    return 0;
}
