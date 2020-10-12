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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

class UnionFind {
private: vi p, rank;
public:
    void initialize(int k) {p.clear(); rank.clear(); rank.assign(k, 0); for (int i = 0; i < k; i++) p.push_back(i);}
    int findSet(int i) {return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
    bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}
    void unionSet(int i, int j) {
        if (isSameSet(i,j)) return;
        int x = p[i]; int y = p[j];
        if (rank[x] > rank[y]) p[y] = x;
        else {p[x] = y; if (rank[x] == rank[y]) rank[y]++;}
    }
};

int T, N, a, b;
int r, w;
string query;
UnionFind S;

int main() {

    cin >> T;
    cin >> N;
    for (int tc = 1; tc <= T; tc++) {
        S.initialize(N+2);
        r = w = 0;
        while (cin >> query, (query.at(0)-'a' > 0 && !cin.eof())) {
            cin >> a >> b;
            if (!query.compare("c")) { // c
                S.unionSet(a,b);
            }
            else { // q
                if (S.isSameSet(a,b)) r++;
                else w++;
            }
        }

        cout << r << "," << w << endl;

        if (tc < T) {
            cout << endl;
            N = stoi(query);
        }
    }

    return 0;
}
