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
#define MAXN 102
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N;
int ans;
int A[MAXN][MAXN];

void printA() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ans = INT_MIN;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            if (i == 0 && j == 0) {}
            else if (i == 0) {
                A[i][j] += A[i][j-1];
            }
            else if (j == 0) {
                A[i][j] += A[i-1][j];
            }
            else {
                A[i][j] += A[i][j-1] + A[i-1][j];
                A[i][j] -= A[i-1][j-1];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int a = 0; a <= i; a++) {
                for (int b = 0; b <= j; b++) {
                    if (a == 0 && b == 0) {
                        ans = max(ans, A[i][j]);
                    }
                    else if (a == 0) {
                        ans = max(ans, A[i][j] - A[i][b-1]);
                    }
                    else if (b == 0) {
                        ans = max(ans, A[i][j] - A[a-1][j]);
                    }
                    else {
                        ans = max(ans, A[i][j] + A[a-1][b-1] - A[i][b-1] - A[a-1][j]);
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
