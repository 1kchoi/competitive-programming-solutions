// Codeforces ####A - Digit Game
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N, Q[2][2];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        memset(Q,0,sizeof(Q));
        cin >> N;
        string s; cin >> s;
        for (int i = 0; i < N; i++) {
            int a = s[i] - '0';
            Q[(i+1)%2][a%2]++;
        }
        if (N%2) { // N is odd => odd (P1) makes last move
            //cout << Q[1][1] << endl;
            if (Q[1][1]) {
                cout << 1 << endl;
            }
            else {
                cout << 2 << endl;
            }
        }
        else { // N is even => even (P2) makes last move
            //cout << Q[0][0]>0 << endl;
            if (Q[0][0]) {
                cout << 2 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }

    }

    return 0;
}
