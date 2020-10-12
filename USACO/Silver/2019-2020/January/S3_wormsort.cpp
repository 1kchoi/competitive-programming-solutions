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
#define cout fout
#define cin fin
#define endl "\n"
#define ll long long
#define NMAX (int)(1e5 + 5)
#define PB push_back
typedef pair<int,int> ii;
typedef pair<int,ii> iii; // weight, (v,u)
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;

ifstream fin("wormsort.in");
ofstream fout("wormsort.out");

int N, M, input;
bool sortedflag;
bool cowInPlace[NMAX];
viii wormholes;
int currentnumholes;
int dfsstart;
bool visited[NMAX];
vvi AL;
int ans;

bool iiiSort(iii a, iii b) {
    return a.first > b.first;
}
void printWormholes() {
    cout << "WORMHOLES:\n";
    for (int i = 0; i < wormholes.size(); i++) {
        cout << "(" << wormholes[i].first << ") " << wormholes[i].second.first << " " << wormholes[i].second.second << endl;
    }
    cout << "-\n";
}

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < AL[v].size(); i++) {
        int u = AL[v][i];
        if (!visited[u]) {
            dfs(u);
        }
    }
}

bool verify(int x) {
    AL.clear(); AL.assign(N, vi());
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < x; i++) {
        ii edge = wormholes[i].second;
        AL[edge.first].PB(edge.second);
        AL[edge.second].PB(edge.first);
    }
    /*
    for (int i = 0; i < AL.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < AL[i].size(); j++) {
            cout << AL[i][j] << " ";
        }
        cout << endl;
    }
    //*/
    dfs(dfsstart);
    /*
    cout << "VISITED:";
    for (int i = 0; i < N; i++) {
        cout << visited[i];
    }
    cout << endl;
    cout << "COWINNPLACE:";
    for (int i = 0; i < N; i++) {
        cout << cowInPlace[i];
    }
    cout << endl;
    //*/
    for (int i = 0; i < N; i++) {
        //cout << i << " ";
        if (!cowInPlace[i] && !visited[i]) {
            //cout << "false\n";
            return false;
        }
    }
    //cout << "true\n";
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    sortedflag = false;
    ans = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int c; cin >> c; c--;
        if (i == c) {
            cowInPlace[i] = true;
        }
        else {
            cowInPlace[i] = false;
            dfsstart = i;
        }
        sortedflag = ( sortedflag || !(cowInPlace[i]) );
    }
    if (!sortedflag) cout << -1 << endl;
    else {
        for (int i = 0; i < M; i++) {
            int w, v, u;
            cin >> v >> u >> w;
            v--; u--;
            wormholes.PB(iii(w,ii(v,u)));
        }
        sort(wormholes.begin(), wormholes.end(), iiiSort);
        //printWormholes();
        int lo = 0, hi = M;
        currentnumholes = 0;
        while (hi > lo) {
            int mid = (lo + hi) / 2;
            //cout << lo << " " << mid << " " << hi << endl;
            if (verify(mid)) {
                ans = mid;
                if (hi == mid) break;
                hi = mid;
            }
            else {
                if (lo == mid) break;
                lo = mid;
            }
            //cout << "-\n";
        }
        cout << wormholes[ans-1].first << endl;
    }



    return 0;
}
