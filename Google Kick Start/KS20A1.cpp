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
#define MAXN (int) 1e5+5
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int h[MAXN];
int T, x, N, B, sum, ans, largest;

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        memset(h, 0, sizeof(h));
        sum = 0;
        ans = 0;
        largest = 0;
        cin >> N >> B;
        for (int i = 0; i < N; i++) {
            cin >> x;
            h[x]++;
            largest = max(x, largest);
        }
        for (int i = 1; i <= largest; i++) {
            //cout << i << ": " << h[i] << endl;
            while (h[i] > 0 && sum + i <= B) {
                sum += i;
                ans++;
                h[i]--;
            }
            if (sum>=B) break;
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}
