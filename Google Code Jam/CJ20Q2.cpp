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
#define MAXN 103
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T;
int S[MAXN];
int len, level, it;
string input;

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> input;
        len = input.length();
        level = it = 0;
        for (int i = 0; i < len; i++) {
            S[i] = stoi(input.substr(i,1));
        }
        cout << "Case #" << tc << ": ";
        while (it < len) {
            if (level < S[it]) {
                level++;
                cout << "(";
            }
            else if (level > S[it]) {
                level--;
                cout << ")";
            }
            else { //equal
                cout << S[it];
                it++;
            }
        }
        while (level > 0) {
            cout << ")";
            level--;
        }
        cout << endl;
    }
    return 0;
}
