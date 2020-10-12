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
#define MAXN (int)1e4 + 5
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

class UnionFind {
private:
    vi p, rank;
public:
    vvi enemies;
    void initialize(int N) {
        rank.assign(N, 0);
        //p.assign(N, 0);
        for (int i = 0; i < N; i++) {
            p.push_back(i);
        }
        vi emptyvector;
        for (int i = 0; i < N; i++) {
            enemies.push_back(emptyvector);
        }
    }
    int findSet(int i) {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i,j)) {
            int x = findSet(i);
            int y = findSet(j);
            int alpha, beta;
            if (rank[x] > rank[y]) {
                p[y] = x;
                alpha = x; beta = y;
            }
            else {
                p[x] = y;
                alpha = y; beta = x;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
            for (int i = 0; i < enemies[beta].size(); i++) {
                enemies[alpha].push_back(enemies[beta][i]);
            }
            enemies[beta].clear();
        }
    }
    void print(int N) {
        for (int i = 0; i < N; i++) {
            cout << i << " [" << p[i] << "]: ";
            for (int j = 0; j < enemies[i].size(); j++) {
                cout << enemies[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int N;
int command, arg1, arg2;
UnionFind ufds;

void setFriends(int a, int b);

bool areFriends(int a, int b) { // 3
    int aset = ufds.findSet(a);
    int bset = ufds.findSet(b);
    if (ufds.isSameSet(a,b)) {
        return true;
    }
    for (int i = 0; i < ufds.enemies[aset].size(); i++) {
        if (ufds.enemies[aset][i] == bset) {
            return false;
        }
        if (find(ufds.enemies[bset].begin(), ufds.enemies[bset].end(), ufds.enemies[aset][i]) != ufds.enemies[bset].end()) {
            setFriends(a,b);
            return true;
        }
    }
    return false;
}
bool areEnemies(int a, int b) { // 4
    int aset = ufds.findSet(a);
    int bset = ufds.findSet(b);
    if (find(ufds.enemies[aset].begin(), ufds.enemies[aset].end(), bset) != ufds.enemies[aset].end()) {
        return true;
    }
    return false;
}
void setFriends(int a, int b) { // 1
    if (areEnemies(a,b)) {
        cout << -1 << endl; return;
    }
    else {
        ufds.unionSet(a,b);
    }
}
void setEnemies(int a, int b) { // 2
    if (areFriends(a,b)) {
        cout << -1 << endl; return;
    }
    int aset = ufds.findSet(a);
    int bset = ufds.findSet(b);
    ufds.enemies[aset].push_back(bset);
    ufds.enemies[bset].push_back(aset);
}

int main() {

    cin >> N;
    ufds.initialize(N);



    while (scanf("%d %d %d", &command, &arg1, &arg2), command > 0) {
        if (command == 1) {
            setFriends(arg1, arg2);
        }
        else if (command == 2) {
            setEnemies(arg1, arg2);
        }
        else if (command == 3) {
            cout << areFriends(arg1, arg2) << endl;
        }
        else if (command == 4) {
            cout << areEnemies(arg1, arg2) << endl;
        }
        else {
            cout << "bruh" << endl;
        }
        ufds.print(N);
    }

    return 0;
}
