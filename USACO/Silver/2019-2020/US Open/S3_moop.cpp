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
#define NMAX (int)(1e5 + 5)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("moop.in");
ofstream fout("moop.out");

class UnionFind {
private: vi p, rank;
public:
    void initialize(int k) {rank.assign(k,0); for(int i = 0; i <= k; i++) p.push_back(i);}
    int findSet(int x) {if(x == p[x]) return x; else return p[x] = findSet(p[x]);}
    bool isSameSet(int a, int b) {return findSet(a) == findSet(b);}
    void unionSet(int i, int j) {
        int x = findSet(i); int y = findSet(j);
        if (x != y) {
            if (rank[x] > rank[y]) {
                p[y] = x;
            }
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int N, x, y, ans;
vii points;
UnionFind UF;
bool tagged[NMAX];
bool uniqueSets[NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    UF.initialize(N);
    memset(tagged, 0, sizeof(tagged));
    memset(uniqueSets, 0, sizeof(uniqueSets));
    ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        points.push_back(ii(x,y));
    }

    sort(points.begin(), points.end());

    for (int i = 0; i < N; i++) {
        if (!tagged[i]) {
            tagged[i] = 1;
            for (int j = i+1; j < N; j++) {
                if (points[j].second >= points[i].second) {
                    UF.unionSet(i,j);
                    tagged[j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!uniqueSets[UF.findSet(i)]) {
            ans++;
            uniqueSets[UF.findSet(i)] = 1;
        }
    }

    cout << ans << endl;

    return 0;
}
