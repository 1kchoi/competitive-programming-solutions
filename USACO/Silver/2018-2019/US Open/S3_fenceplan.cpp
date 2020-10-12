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
#define PB push_back
#define XMIN first.first
#define XMAX first.second
#define YMIN second.first
#define YMAX second.second
#define NMAX (int)(1e5+2)
typedef pair<int,int> ii;
typedef pair<ii, ii> iiii; // (xmin, xmax), (ymin, ymax)
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("fenceplan.in");
ofstream fout("fenceplan.out");

class UFDS {
private: vi p, rank;
public:
    void initialize (int n) {
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) {
            p.PB(i);
        }
    }
    int findSet(int i) {return (i == p[i]) ? i : p[i] = findSet(p[i]);}
    bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}
    void unionSet (int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x == y) return;
        if (rank[x] > rank[y]) {
            p[y] = x;
        }
        else {
            p[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
};

int N, M;
vii coords;
iiii sizes[NMAX];
vi sets;
UFDS UF;
int ans = INT_MAX;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    UF.initialize(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        coords.PB(ii(++a,++b));
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        UF.unionSet(--a,--b);
    }
    for (int i = 0; i < N; i++) {
        int q = UF.findSet(i);
        int minX = sizes[q].XMIN;
        int maxX = sizes[q].XMAX;
        int minY = sizes[q].YMIN;
        int maxY = sizes[q].YMAX;
        if (!minX || coords[i].first < minX) {
            sets.PB(q);
            sizes[q].XMIN = coords[i].first;
        }
        if (!maxX || coords[i].first > maxX) {
            sizes[q].XMAX = coords[i].first;
        }
        if (!minY || coords[i].second < minY) {
            sizes[q].YMIN = coords[i].second;
        }
        if (!maxY || coords[i].second > maxY) {
            sizes[q].YMAX = coords[i].second;
        }
    }

    for (int i = 0; i < sets.size(); i++) {
        iiii thisSet = sizes[sets[i]];
        ans = min(ans, 2*(thisSet.XMAX - thisSet.XMIN + thisSet.YMAX - thisSet.YMIN));
    }

    cout << ans << endl;

    return 0;
}
