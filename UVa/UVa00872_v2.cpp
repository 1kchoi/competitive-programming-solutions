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
bool candidate[VMAX];
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
    cout << "topo: ";
    for (int i = 0; i < topo.size(); i++){
        //cout << (char)(topo[i]+'A') << " ";
        cout << topo[i] << " ";
    }
    cout << endl;
}

void printCandidate() {
    cout << "candidate:";
    for (int i = 0; i < VMAX; i++) {
        if (candidate[i]) cout << " " << i;
    }
    cout << endl;
}

void dfs(int v) {
    topo.push_back(v);
    candidate[v] = false;

    if (topo.size() == vcount) {
        cout << "FOUND ";
        printTopo();
        FLAG = true;
    }
    else {
        bool candidatecopy[VMAX];
        copy(candidate, candidate+VMAX, candidatecopy);

        //printTopo();

        for (int i = 0; i < topo.size(); i++) { // for every vertex in topo
            //cout << "i:" << i << " topo[i]:" << topo[i] << endl;
            for (int j = 0; j < AL[topo[i]].size(); j++) { // for every neighbor of vertex i
                if (find(topo.begin(), topo.end(), AL[topo[i]][j]) == topo.end()) { // if AL[i][j] is not in topo
                    if (find(EL.begin(), EL.end(), make_pair())){
                        candidate[AL[topo[i]][j]] = true;
                    }
                }
            }
        }

        //printCandidate();

        for (int i = 0; i < VMAX; i++) {
            if (candidate[i]) {
                dfs(i);
            }
        }

        copy (candidatecopy, candidatecopy+VMAX, candidate);
    }

    topo.pop_back();
    candidate[v] = true;
}

int main() {

    cin >> T;
    getline(cin, input);

    while (T--) {
        getline(cin, input);
        vcount = 0;
        FLAG = false;
        memset(allV, 0, sizeof(allV));
        EL.clear();
        initializeAL();
        getline(cin, input);
        for (int i = 0; i < input.length(); i += 2) {
            allV[input.at(i) - 'A'] = true;
            vcount++;
        }
        copy(allV, allV + VMAX, candidate);
        getline(cin, input);
        for (int i = 0; i < input.length(); i+= 4) {
            p = make_pair((int)(input.at(i) - 'A'), (int)(input.at(i+2) - 'A'));
            candidate[p.second] = false;
            EL.push_back(p);
        }
        for (int i = 0; i < EL.size(); i++) {
            AL[EL[i].first].push_back(EL[i].second);
        }

        printAL();
        //printCandidate();

        for (int i = VMAX-1; i >= 0; i--) {
            if (candidate[i]) {
                dfs(i);
            }
        }
        if (!FLAG) {
            cout << "NO" << endl;
        }

    }

    return 0;
}
