// CSES Problem Set - Common Divisors
#include <iostream>
#define NMAX (int)(1e6+5)
using namespace std;

int N, freq[NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        for (int j = 1; j*j <= a; j++) {
            if (a % j == 0) {
                freq[j]++;
                if (j != a/j) freq[a/j]++;
            }
        }
    }
    for (int i = NMAX-1; i >= 1; i--) {
        if (freq[i] >= 2) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
