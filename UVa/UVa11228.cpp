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
#define cin fin
#define ll long long
#define NMAX 1005
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

class UnionFind {
private: vi p, rank;
public:
    void initialize(int N) {
        p.clear();
        rank.clear();
        rank.assign(N, 0);
        for (int i = 0; i < N; i++) {
            p.push_back(i);
        }
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i,j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
            }
            else {
                p[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
};

ifstream fin("input.txt");
ofstream fout("output.out");

int T, N, R, xin, yin;
int states;
double roads, rails;
vii points;
vector< pair < double, ii > > EL; // <weight, <point1, point2>>
UnionFind UF;

double calcDistance(int a, int b) {
    return sqrt((points[a].first-points[b].first)*(points[a].first-points[b].first) + (points[a].second-points[b].second)*(points[a].second-points[b].second));
}

int main() {

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> R;

        states = 1;
        roads = rails = 0;
        points.clear();
        EL.clear();
        UF.initialize(N+5);

        for (int i = 0; i < N; i++) {
            cin >> xin >> yin;
            points.push_back(make_pair(xin,yin));
        }

        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                EL.push_back(make_pair(calcDistance(i,j), make_pair(i,j)));
            }
        }
        sort(EL.begin(), EL.end());

        for (int i = 0; i < EL.size(); i++) {
            //cout << EL[i].first << " (" << EL[i].second.first << EL[i].second.second << ")" << endl;
        }

        for (int i = 0; i < EL.size(); i++) {
            int v = EL[i].second.first;
            int u = EL[i].second.second;
            if (!UF.isSameSet(v,u)) {
                UF.unionSet(v,u);
                if (EL[i].first > R) { // v and u in different states
                    //cout << v << " " << u << " rail" << endl;
                    states++;
                    rails += EL[i].first;
                }
                else {
                    //cout << v << " " << u << " road" << endl;
                    roads += EL[i].first;
                }
            }
        }
        cout << "Case #" << tc << ": " << states << " " << (int)(round(roads)) << " " << (int)(round(rails)) << endl;
    }

    return 0;
}
