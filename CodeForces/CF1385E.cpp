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
//#define cout fout
//#define cin fin
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(2*(1e5)+5)
typedef pair<int,int> ii;
typedef pair<int, bool> ib;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ib> vib;
typedef vector<vi> vvi;
typedef vector<vib> vvib;


ifstream fin("input.in");
ofstream fout("output.out");

vvib AL;
bool discovered[NMAX];
vi indegree;
vii sortedID; // indegree, vertex
vii undirectedEL;
vi path;
int t, n, m;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        AL.clear();
        AL.assign(n, vib());
        indegree.clear();
        indegree.assign(n,0);
        for (int i = 0; i < m; i++) {
            bool dir;
            int v,u;
            cin >> dir >> v >> u;
            v--; u--;
            AL[v].PB(ib(u,dir));
            indegree[u]++;
            if (!dir) {
                AL[u].PB(ib(v,dir));
                indegree[v]++;
            }
        }
        for (int i = 0; i < indegree.size(); i++) {
            sortedID.PB(ii(indegree[i], i));
        }
        sort(sortedID.begin(), sortedID.end());
        for (int i = 0; i < sortedID.size(); i++) {
            if (!discovered[sortedID[i].second]) {

                //dfs
            }
        }
    }

    return 0;
}
