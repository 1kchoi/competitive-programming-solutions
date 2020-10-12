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
#define MAXV 28
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int TC;
bool letters[27];
string s;
int e, v, acorns;

int main() {

    cin >> TC;

    while (TC--) {
        e = 0; v = 0; acorns = 0;
        memset(letters, 0, 27);
        while (true) {
            cin >> s;
            if (s.substr(0,1).compare("*") == 0) break;
            letters[s.at(1)-'A'] = true;
            letters[s.at(3)-'A'] = true;
            e++;
        }
        cin >> s;
        v = (s.length()+1)/2;
        for (int i = 0; i < s.length(); i += 2) {
            if (letters[s.at(i)-'A'] == false) {
                acorns++;
            }
        }
        cout << "There are " << v-e-acorns << " tree(s) and " << acorns << " acorn(s)." << endl;
    }

    return 0;
}
