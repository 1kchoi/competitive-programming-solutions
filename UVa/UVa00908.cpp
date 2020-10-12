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
#define NMAX (int)(1e6 + 3)
#define ll long long
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

ifstream fin("input.txt");
ofstream fout("output.out");

priority_queue<ii> Q;
vvii AL;
int N, M, K, input, mst1, mst2;
int a, b, c;
bool taken[NMAX];
bool STARTFLAG;

void initializeAL(int x) {
    AL.clear();
    vii empty;
    AL.assign(x, empty);
}

void printAL() {
    for (int i = 0; i < AL.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < AL[i].size(); j++) {
            cout << AL[i][j].first << " (" << AL[i][j].second << "), ";
        }
        cout << endl;
    }
    cout << endl;
}

void process(int v) {
    taken[v] = true;
    for (int i = 0; i < AL[v].size(); i++) {
        ii u = AL[v][i];
        if (!taken[u.first]) {
            Q.push(ii(-u.second, -u.first));
        }
    }
}

int main() {

    STARTFLAG = true;

    while (cin >> N, !cin.eof()) {
        if (STARTFLAG) {
            STARTFLAG = false;
        }
        else {
            cout << endl;
        }
        initializeAL(N+3);
        mst1 = mst2 = 0;
        memset(taken, 0, sizeof(taken));

        for (int i = 0; i < N-1; i++) {
            cin >> input >> input >> input;
            mst1 += input;
        }

        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> a >> b >> c;
            AL[a].push_back(ii(b,c));
            AL[b].push_back(ii(a,c));
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            AL[a].push_back(ii(b,c));
            AL[b].push_back(ii(a,c));
        }

        cout << mst1 << endl;

        process(1);

        while (!Q.empty()) {
            ii front = Q.top(); // weight, neighbor
            Q.pop();
            int w = -front.first, v = -front.second;
            if (!taken[v]) {
                mst2 += w;
                process(v);
            }
        }

        cout << mst2 << endl;

    }

    return 0;
}
