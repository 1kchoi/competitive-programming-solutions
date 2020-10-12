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
#define ll long long
#define PB push_back
#define NMAX 2505
#define endl "\n"
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("clocktree.in");
ofstream fout("clocktree.out");

vvi G;
int N, ain, bin;
int clocks[NMAX];
int parity[NMAX];
int parent[NMAX];
int totalmod, ans;
queue<int> Q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    G.assign(NMAX, vi());

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> clocks[i];
    }

    for (int i = 0; i < N-1; i++) {
        cin >> ain >> bin;
        ain--; bin--;
        G[ain].PB(bin);
        G[bin].PB(ain);
    }

    Q.push(0);
    parity[0] = 1;
    totalmod += clocks[0]; totalmod %= 12;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < G[v].size(); i++) { // for every neighbor of v
            int u = G[v][i]; // u is neighbor of v
            if (!parity[u]) {
                parity[u] = parity[v]*-1;
                totalmod += clocks[u]*parity[u] + 24; totalmod %= 12;
                //cout << totalmod << endl;
                Q.push(u);
            }
        }
    }

    if (totalmod == 11) totalmod = -1;

    //cout << totalmod << endl;

    if (totalmod == 0) {
        ans = N;
    }
    else {
        for (int i = 0; i < N; i++) {
            ans += (totalmod == parity[i]);
            //cout << totalmod << " " << parity[i] << endl;
        }
    }

    cout << ans << "\n";


    return 0;
}
