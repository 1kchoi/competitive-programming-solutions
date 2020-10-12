#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define NMAX 100002

int T, N, P;
int sum, ans;
int S[NMAX];

int main() {
    scanf("%d", &T);

    for (int c = 1; c <= T; c++) {
        sum = 0;
        ans = INT_MAX;
        scanf("%d %d", &N, &P);

        for (int i = 0; i < N; i++) scanf("%d", &S[i]);
        sort(S, S+N);

        for (int i = 0; i < N; i++) {
            sum += S[i];

            if (i+1 >= P) {
                int potential = S[i]*P - sum;
                ans = min(ans, potential);

                sum -= S[i+1-P];
            }
        }

        printf("Case #%d: %d\n", c, ans);
    }
}
