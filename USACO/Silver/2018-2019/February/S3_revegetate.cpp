// Now I am become Death, the destroyer of worlds.
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <complex>
#include <climits>
#include <fstream>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
typedef pair<int,int> ii;
typedef pair<int, bool> ib;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ib> vib;
typedef vector<vi> vvi;

int N, M;
vib G[NMAX]; // 0 is same, 1 is different
bool discovered[NMAX];
int ans;

void bfs(int s) {
    bool parity[NMAX];
    memset(parity,0,sizeof(parity));
    queue<int> Q; Q.push(s);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (ib u : G[v]) {
            if (discovered[u.first] && parity[u.first] != (parity[v]+u.second)%2) return;
            if (!discovered[u.first]) {
                discovered[u.first] = 1;
                parity[u.first] = (parity[v]+u.second)%2;
                Q.push(u.first);
            }
        }
    }
    ans++;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        char c; int a, b;
        cin >> c >> a >> b; --a; --b;
        G[a].PB(ib(b,c=='D'));
        G[b].PB(ib(a,c=='D'));
    }

    for (int i = 0; i < N; i++) if (!discovered[i]) bfs(i);

    if (!ans) cout << 0 << endl;
    else {
        cout << 1;
        for (int i = 0; i < ans; i++) cout << 0;
        cout << endl;
    }

    return 0;
}
