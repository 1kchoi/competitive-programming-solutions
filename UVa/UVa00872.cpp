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
bool current[VMAX];
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
        cout << (char)(i + 'A') << ": ";
        for (int j = 0; j < AL[i].size(); j++) {
            cout << (char)(AL[i][j] + 'A') << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printTopo() {
    for (int i = 0; i < topo.size(); i++){
        cout << (char)(topo[i]+'A') << " ";
    }
    cout << endl;
}

void printCurrent() {
    cout << "current:";
    for (int i = 0; i < VMAX; i++) {
        if (current[i]) cout << " " << i;
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

    if (FLAG) return;

    current[v] = true;
    candidate[v] = false;
    printCurrent();

    if (topo.size() == vcount) {
        FLAG = true;
        printTopo();
    }
    else {
        bool candidateold[VMAX];
        copy(candidate, candidate+VMAX, candidateold);

        for (int i = 0; i < VMAX; i++) {
            if (current[i]) {
                for (int j = 0; j < AL[i].size(); j++) {
                    candidate[AL[i][j]] = true;
                }
            }
        }

        printCandidate();


        for (int i = 0; i < VMAX; i++) {
            if (candidate[i]) {
                if (find(topo.begin(), topo.end(), i) == topo.end()) {
                    topo.push_back(i);
                    dfs(i);
                    topo.pop_back();
                }
            }
        }

        copy(candidateold, candidateold+VMAX, candidate);
    }

    current[v] = false;
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

        for (int i = 0; i < VMAX; i++) {
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
