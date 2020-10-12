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

int T, N;
int trace, row, col;
int A[MAXN][MAXN];
bool check[MAXN];

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        trace = row = col = 0;
        for (int i = 0; i < N; i++) {
            memset(check, false, MAXN);
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];

            }
            trace += A[i][i];
        }

        for (int i = 0; i < N; i++) {
            memset(check, false, MAXN);
            for (int j = 0; j < N; j++) {
                if (check[A[i][j]]) {
                    row++;
                    break;
                }
                else {
                    check[A[i][j]] = true;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            memset(check, false, MAXN);
            for (int j = 0; j < N; j++) {
                if (check[A[j][i]]) {
                    col++;
                    break;
                }
                else {
                    check[A[j][i]] = true;
                }
            }
        }
        cout << "Case #" << tc << ": " << trace << " " << row << " " << col << endl;
    }

    return 0;
}
