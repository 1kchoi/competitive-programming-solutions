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
#define VMAX 28
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

int T, vcount;
string input;
vii EL;
vvi AL;
ii p;
bool allV[VMAX];
int indegree[VMAX];
vi topo;
bool FLAG;

void initializeAL() {
    AL.clear();
    vi empty;
    for (int i = 0; i < VMAX; i++) {
        AL.push_back(empty);
    }
}

void printAL() {
    for (int i = 0; i < VMAX; i++) {
        //cout << (char)(i + 'A') << ": ";
        cout << i << ": ";
        for (int j = 0; j < AL[i].size(); j++) {
            //cout << (char)(AL[i][j] + 'A') << " ";
            cout << AL[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printTopo() {
    //cout << "topo: ";
    for (int i = 0; i < topo.size(); i++){
        cout << (char)(topo[i]+'A');
        if (i < topo.size()-1) {
            cout << " ";
        }
        //cout << topo[i] << " ";
    }
    cout << endl;
}

void dfs(int v) {
    topo.push_back(v);

    if (topo.size() == vcount) {
        //cout << "FOUND ";
        printTopo();
        FLAG = true;
    }
    else {
        for (int i = 0; i < AL[v].size(); i++) { //for all neighbors of v
            indegree[AL[v][i]]--;
        }

        for (int i = 0; i < VMAX; i++) {
            if (indegree[i] == 0 && find(topo.begin(), topo.end(), i) == topo.end()) { // if nothing coming in and not in topo
                dfs(i);
            }
        }

        for (int i = 0; i < AL[v].size(); i++) { //for all neighbors of v
            indegree[AL[v][i]]++;
        }
    }

    topo.pop_back();
}

int main() {

    cin >> T;
    getline(cin, input);

    while (T--) {
        getline(cin, input);
        vcount = 0;
        FLAG = false;
        memset(allV, 0, sizeof(allV));
        memset(indegree, -1, sizeof(indegree));
        EL.clear();
        initializeAL();
        getline(cin, input);
        for (int i = 0; i < input.length(); i += 2) {
            allV[input.at(i) - 'A'] = true;
            indegree[input.at(i) - 'A'] = 0;
            vcount++;
        }
        getline(cin, input);
        for (int i = 0; i < input.length(); i+= 4) {
            p = make_pair((int)(input.at(i) - 'A'), (int)(input.at(i+2) - 'A'));
            indegree[p.second]++;
            EL.push_back(p);
        }
        for (int i = 0; i < EL.size(); i++) {
            AL[EL[i].first].push_back(EL[i].second);
        }

        for (int i = 0; i < VMAX; i++) {
            if (indegree[i] == 0) {
                dfs(i);
            }
        }
        if (!FLAG) {
            cout << "NO" << endl;
        }
        if (T > 0) cout << endl;

    }

    return 0;
}
