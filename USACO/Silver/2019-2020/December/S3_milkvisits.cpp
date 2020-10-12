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
#define NMAX (int)(1e5+5)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

class UFDS {
private: vi p, rank;
public:
    void initialize(int n) {
        rank.assign(n,0);
        for (int i = 0; i < n; i++) {
            p.PB(i);
        }
    }
    int findSet(int i) {return i==p[i] ? i : p[i]=findSet(p[i]);}
    bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}
    void unionSet(int i, int j) {
        int x = p[i], y = p[j];
        //cout << x << " " << y << endl;
        if (x!=y) {
            //cout << "loser" << endl;

            if (rank[x] > rank[y]) {
                p[y] = x;
            }
            else {
                p[x] = y;
                if (rank[x]==rank[y]) rank[y]++;
            }
        }
    }
};

//ifstream fin("input.in");
//ofstream fout("output.out");


int N, M;
bool cowbreed[NMAX];
UFDS S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    cin >> N >> M;
    S.initialize(N);
    string r; cin >> r;
    for (int i = 0; i < N; i++) {
        cowbreed[i] = (r.at(i)=='H');
    }
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        //cout << a << " " << b << endl;
        if (cowbreed[a]==cowbreed[b]) {
            //cout << "union: " << a << " " << b << endl;
            S.unionSet(a,b);
        }
    }
    //cout << "hi" << endl;

    for (int i = 0; i < M; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        --a; --b;
        //cout << a << " " << b << " " << c << endl;
        //cout << S.isSameSet(a,b) << " " << cowbreed[a] << " " << (c=='H') << endl;
        cout << (!S.isSameSet(a,b) || cowbreed[a] == (c=='H'));
        //cout << endl;
    }
    cout << endl;
    return 0;
}
