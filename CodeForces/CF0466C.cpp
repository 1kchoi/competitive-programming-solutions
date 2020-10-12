// Codeforces 466C. Number of Ways
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(5e5+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N;
ll A[NMAX], P[NMAX], x1, x2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        P[i+1] = P[i] + A[i];
    }

    if (P[N] % 3 != 0 || N < 3) {
        cout << 0 << endl;
    }
    else if (!P[N]) {
        ll count = 0;
        for (int i = 1; i <= N; i++) {
            if (!P[i]) count++;
        }
        cout << (count-2)*(count-1)/2 << endl;
    }
    else { 
        for (int i = 0; i < N; i++) {
            if (P[i] == P[N]/3) {
                x1++;
            }
            else if (P[i] == P[N]*2/3) {
                x2++;
            }
        }
        cout << x1*x2 << endl;
    }

    return 0;
}
