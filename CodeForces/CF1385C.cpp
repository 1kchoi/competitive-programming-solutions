
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
vi a;
bool rising, found;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        a.clear();
        //cout << "t: " << t << endl;
        cin >> n;
        rising = true;
        found = false;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.PB(x);
        }
        for (int i = a.size()-1; i >= 1; i--) {
            if (a[i] < a[i-1]) {
                if (!rising) {
                    found = true;
                    cout << i << endl;
                    break;
                }
            }
            else if (a[i] > a[i-1]){
                rising = false;
            }
        }
        if (!found) cout << 0 << endl;
    }

    return 0;
}
