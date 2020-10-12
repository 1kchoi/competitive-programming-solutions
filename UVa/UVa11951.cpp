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
#define NMAX 102
#define KMAX (int)(1e9 + 3)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

int T, N, M, K, input;
int grid[NMAX][NMAX];
int least[NMAX*NMAX];
bool FLAG;

void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> M >> K;
        FLAG = false;
        memset(least, -1, sizeof(least));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> input;
                if (i == 0 && j == 0) {
                    grid[i][j] = input;
                }
                else if (i == 0) {
                    grid[i][j] = grid[i][j-1] + input;
                }
                else if (j == 0) {
                    grid[i][j] = grid[i-1][j] + input;
                }
                else {
                    grid[i][j] = grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1] + input;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = i; k < N; k++) {
                    for (int l = j; l < M; l++) {
                        int value;
                        int size = (k-i+1)*(l-j+1);
                        if (i == 0 && j == 0) {
                            value = grid[k][l];
                        }
                        else if (i == 0) {
                            value = grid[k][l] - grid[k][j-1];
                        }
                        else if (j == 0) {
                            value = grid[k][l] - grid[i-1][l];
                        }
                        else {
                            value = grid[k][l] - grid[i-1][l] - grid[k][j-1] + grid[i-1][j-1];
                        }

                        if (least[size] == -1 || least[size] > value) {
                            least[size] = value;
                        }
                    }
                }
            }
        }

        for (int i = N*M; i >= 1 && !FLAG; i--) {
            if (least[i] > -1 && least[i] <= K) {
                cout << "Case #" << tc << ": " << i << " " << least[i] << endl;
                FLAG = true;
            }
        }
        if (!FLAG) {
            cout << "Case #" << tc << ": " << 0 << " " << 0 << endl;
        }
    }

    return 0;
}
