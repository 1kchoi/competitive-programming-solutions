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

vi s;
bool b[51];
int t, n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        memset(b,0,sizeof(b));
        for (int i = 0; i < 2*n; i++) {
            int a; cin >> a;
            if (!b[a]) {
                b[a] = true;
                if (!i) {
                    cout << a;
                }
                else {
                    cout << " " << a;
                }

            }
        }
        cout << endl;
    }

    return 0;
}
