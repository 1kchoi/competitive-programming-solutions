// IOI 2013 (Brisbane) Day 2 - Problem 2 - Robots
#include <bits/stdc++.h>
//#include "robots.h"
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define TMAX (int)(1e6+5)
#define AMAX (int)(5e4+4)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int A, B, T, X[AMAX], Y[AMAX], W[TMAX], S[TMAX];
int toyorderW[TMAX], toyorderS[TMAX];

bool sortW(int i, int j) {
    return W[i] < W[j];
}

bool sortS(int i, int j) {
    return S[i] < S[j];
}

/*
bool check(int C) {
    return true;
}
*/

int putaway(int A0, int B0, int T0, int X0[], int Y0[], int W0[], int S0[]) {
    A = A0; B = B0; T = T0;
    memcpy(X, X0, sizeof(&X0));
    memcpy(Y, Y0, sizeof(&Y0));
    memcpy(W, W0, sizeof(&W0));
    memcpy(S, S0, sizeof(&S0));

    for (int i = 0; i < T; i++) {
        toyorderW[i] = i;
        toyorderS[i] = i;
    }

    sort(X, X + A);
    sort(Y, Y + B);

    sort(toyorderW, toyorderW + T, sortW);
    sort(toyorderS, toyorderS + T, sortS);

    for (int i = 0; i < T; i++) {
        cout << toyorderW[i] << " " << W[toyorderW[i]] << " " << S[toyorderW[i]] << endl;
    }
    cout << endl;

    for (int i = 1; i < A; i++) {
        cout << *upper_bound(toyorderW, toyorderW + T, X[i - 1], sortW) << endl;
        sort(upper_bound(toyorderW, toyorderW + T, X[i - 1], sortW), upper_bound(toyorderW, toyorderW + T, X[i], sortW), sortS);

        cout << "i = " << i << ":" << endl;
        for (int j = 0; j < T; j++) {
            cout << toyorderW[j] << " " << W[toyorderW[j]] << " " << S[toyorderW[j]] << endl;
        }
        cout << endl;
    }
    sort(toyorderW, upper_bound(toyorderW, toyorderW + T, X[0], sortW), sortS);
    sort(upper_bound(toyorderW, toyorderW + T, X[A - 1], sortW), toyorderW + T, sortS);

    cout << "FINAL: " << endl;
    for (int i = 0; i < T; i++) {
        cout << toyorderW[i] << " " << W[toyorderW[i]] << " " << S[toyorderW[i]] << endl;
    }
    cout << endl;


/*
    int l = 1, r = T, ans = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return ans;
    */
    return 69;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> A >> B >> T;
    for (int i = 0 ; i < A; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < B; i++) {
        cin >> Y[i];
    }
    for (int i = 0; i < T; i++) {
        cin >> W[i] >> S[i];
    }
    putaway(A, B, T, X, Y, W, S);
    //cout << putaway(A, B, T, X, Y, W, S) << endl;

    return 0;
}
