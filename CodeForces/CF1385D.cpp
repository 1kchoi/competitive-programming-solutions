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

int t, n;
string c;
vi s;
int ans;

void backtrack(int start, int length, int x, int moves) {
    if (length == 1) {
        ans = min(ans, moves + (s[start] != x));
    }
    else {
        int first = 0, second = 0;
        for (int i = start; i < start + length/2; i++) {
            if (s[i] != x) first++;
        }
        for (int i = start + length/2; i < start + length; i++) {
            if (s[i] != x) second++;
        }
        backtrack(start, length/2, x+1, moves+second);
        backtrack(start+length/2, length/2, x+1, moves+first);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> c;
        s.clear();
        ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            s.PB(c.at(i)-'a');
        }
        backtrack(0,n,0,0);
        cout << ans << endl;
    }

    return 0;
}
