// USACO 2021 January Contest, Silver
// Problem 2. No Time to Paint
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, Q;
string S;
int st[NMAX], en[NMAX];
vector<char> B;

void fillSum(int* A) {
    B.clear();
    for (int i = 0; i < N; i++) {
        while (sz(B) && B[sz(B) - 1] > S[i]) {
            B.pop_back();
        }
        A[i + 1] = A[i];
        if (!sz(B) || B[sz(B) - 1] != S[i]) {
            B.PB(S[i]);
            A[i + 1]++;
        }
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

void printSums() {
    for (int i = 0; i <= N; i++) {
        cout << setw(4) << i;
    }
    cout << endl;
    for (int i = 0; i <= N; i++) {
        cout << setw(4) << st[i];
    }
    cout << endl;
    for (int i = 0; i <= N; i++) {
        cout << setw(4) << en[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> Q >> S;
    fillSum(st);
    reverse(all(S));
    fillSum(en);
    reverse(en + 1, en + N + 1);

    while (Q--) {
        int i, j; cin >> i >> j;
        cout << st[i - 1] + en[j + 1] << endl;
    }


    return 0;
}
