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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.in");
ofstream fout("output.out");

int t;
vi s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        s.clear();
        for (int i = 0; i < 3; i++) {
            int a;
            cin >> a; s.PB(a);
        }
        sort(s.begin(), s.end());
        if (s[0] == s[2]) {
            cout << "YES" << endl << s[0] << " " << s[0] << " " << s[0] << endl;
        }
        else if (s[0] == s[1]) {
            cout << "NO" << endl;
        }
        else if (s[1] == s[2]) {
            cout << "YES" << endl;
            cout << s[1] << " " << s[0] << " 1\n";
        }
        else {
            cout << "NO\n";
        }
    }


    return 0;
}
