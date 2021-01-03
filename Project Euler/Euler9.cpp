// Problem 9 - Special Pythagorean triplet
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

bool isSquare[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    for (int i = 1; i * i < NMAX; i++) {
        isSquare[i * i] = true;
    }

    for (int i = 1; i < 1005; i++) {
        for (int j = 1; j < 10005; j++) {
            if (i*i + j*j < NMAX && isSquare[i*i + j*j]) {
                //cout << i*i << " " << j*j << " " << i*i+j*j << endl;
                if (i + j + (int)(sqrt(i*i + j*j)) == 1000) {
                    cout << i * j * (int)(sqrt(i*i + j*j)) << endl;
                }
            }
        }
    }

    return 0;
}
