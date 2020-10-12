// Codeforces 1421B. Two Arrays
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
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

int T, N, K, A[NMAX];
bool parity;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        parity = 0;
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            if (A[i]*2 > K) {
                cout << 1 << " ";
            }
            else if (A[i]*2 < K) {
                cout << 0 << " ";
            }
            else {
                cout << parity << " ";
                parity = !parity;
            }
        }
        cout << endl;
    }

    return 0;
}
