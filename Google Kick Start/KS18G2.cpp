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
#define MAXN (int) 4e5 + 6
#define MAXQ (int) 1e5 + 5
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N, Q;
int X[MAXN];
int Y[MAXN];
int K[MAXQ];
int A[4];
int B[4];
int C[4];
int M[4];
int maxK, nstudents;

int main() {

    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &N, &Q);
        scanf("%d %d %d %d %d %d", &X[1], &X[2], &A[1], &B[1], &C[1], &M[1]);
        scanf("%d %d %d %d %d %d", &Y[1], &Y[2], &A[2], &B[2], &C[2], &M[2]);
        scanf("%d %d %d %d %d %d", &K[1], &K[2], &A[3], &B[3], &C[3], &M[3]);

        maxK = 0;
        for (int i = 1; i <= Q; i++) { // generating Z
            if (i >= 3) {
                K[i] = (A[3]*(K[i-1]-1) + B[3]*(K[i-2]-1) + C[3]) % M[3];
            }
            K[i]++;
            maxK = max(K[i], maxK);
        }

        for (int i = 1; i <= N; i++) {
            if (i >= 3) {
                X[i] = (A[1]*(X[i-1]-1) + B[1]*(X[i-2]-1) + C[1]) % M[1];
                Y[i] = (A[2]*(Y[i-1]-1) + B[2]*(Y[i-2]-1) + C[2]) % M[2];
            }
            X[i]++;
            Y[i]++;
            if (X[i] > Y[i]) swap(&X[i], &Y[i]);
        }

    }

    return 0;

}
