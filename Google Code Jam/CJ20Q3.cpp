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
#define MAXN 1000
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N, tc;
int start[MAXN];
int stop[MAXN];
bool ans[MAXN];
bool ans2[MAXN];
vi order;
int busy[2];
bool FINISHED;

bool sortFunc(int i, int j) {
    if (start[i] < start[j]) {
        return true;
    }
    else if (start[i] == start[j]) {
        return (stop[i] < stop[j]);
    }
    else return false;
}

void printAns() {
    if (FINISHED) return;
    cout << "Case #" << tc << ": ";
    for (int i = 0; i < N; i++) {
        ans2[order[i]] = ans[i];
    }
    for (int i = 0; i < N; i++) {
        if (ans2[i]) cout << "C";
        else cout << "J";
    }
    cout << endl;
}

void backtrack(int a) {
    if (FINISHED) return;
    if (a == N) {
        printAns();
        FINISHED = true;
    }
    else {
        for (int i = 0; i < 2; i++) {
            if (busy[i] <= start[order[a]]) {
                ans[a] = i;
                int old = busy[i];
                busy[i] = stop[order[a]];

                backtrack(a+1);

                busy[i] = old;
                ans[a] = false;
            }
        }
    }
}

int main() {
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        order.clear();
        busy[0] = busy[1] = 0;
        FINISHED = false;
        memset(ans, false, MAXN);
        memset(ans2, false, MAXN);
        cin >> N;
        for (int n = 0; n < N; n++) {
            cin >> start[n] >> stop[n];
            order.push_back(n);
        }
        sort(order.begin(), order.end(), sortFunc);
        backtrack(0);
        if (!FINISHED) cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
    }

    return 0;
}
