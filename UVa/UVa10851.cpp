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

int T, M;
vector<vector<bool> > code;
string input;
string ans;

void initializeCode() {
    vector<bool> empty;
    code.assign(8, empty);
}

void printCode() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < code[i].size(); j++) {
            cout << code[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    cin >> T;

    while (T--) {
        initializeCode();
        ans.clear();
        cin >> input;
        M = input.length()-2;
        for (int i = 0; i < 8; i++) {
            cin >> input;
            for (int j = 1; j <= M; j++) {
                char c = input.at(j);
                if (c == '/') {
                    code[i].push_back(false);
                }
                else {
                    code[i].push_back(true);
                }
            }
        }
        cin >> input;

        for (int i = 0; i < M; i++) {
            char c = 0;
            for (int j = 0; j < 8; j++) {
                c |= (code[j][i] << j);
            }
            ans.append(1,c);
        }
        cout << ans << endl;
    }

    return 0;
}
