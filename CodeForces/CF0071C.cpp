// Codeforces 71C - Round Table Knights
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N;
bool A[NMAX];

void solve() {
    for (int i = 1; i<=N/3; ++i) {
        //cout << "i " << i << endl;
        if (!(N%i)) {
            for (int j = 0; j<i; j++) {
                bool F = true;
                for (int k = j; k<N; k+=i) {
                    //cout << "k " << k << " " << F << endl;
                    F = (F && A[k]);
                }
                if (F) {
                    cout << "YES" << endl;
                    return;
                }
                //cout << "f " << F << endl;
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i<N; ++i) {
        cin >> A[i];
    }

    solve();

    return 0;
}
