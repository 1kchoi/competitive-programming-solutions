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
#define NMAX 3655
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

int T, N, P, k, ans;
bool calendar[NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--) {
        memset(calendar,0,sizeof(calendar));
        ans = 0;
        cin >> N >> P;
        while (P--) {
            cin >> k;
            for (int i = k; i <= N; i += k) {
                calendar[i] = 1;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (calendar[i] && i%7 > 0 && i%7 < 6) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
