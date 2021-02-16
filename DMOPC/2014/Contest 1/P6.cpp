// DMOPC '14 Contest 1 P6 - Biology Homework
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define KKMAX 3120
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int K, powK[6];
ll N;
double A[KKMAX][KKMAX];

vi getValues(int x) {
    vi ans(K, 0);
    for (int i = 0; i < K; i++) {
        ans[i] = x % K;
        x /= K;
    }
    return ans;
}

void recurse(int x, vi values, int i, int current) {
    if (i == K) {
        A[current][x] += 1. / powK[K];
        return;
    }
    for (int y : values) {
        recurse(x, values, i + 1, current + powK[i] * y);
    }
}

void fillmatrix(int x) {
    recurse(x, getValues(x), 0, 0);
}

void multiply(double P[KKMAX][KKMAX], double Q[KKMAX][KKMAX]) {
    
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> K >> N;
    powK[0] = 1;
    for (int i = 0; i < K; i++) powK[i + 1] = powK[i] * K;

    for (int i = 0; i < powK[K]; i++) {
        fillmatrix(i);
    }

    for (int i = 0; i < powK[K]; i++) {
        for (int j = 0; j < powK[K]; j++) {
            cout << setw(20) << A[i][j];
        }
        cout << endl;
    }

    return 0;
}
