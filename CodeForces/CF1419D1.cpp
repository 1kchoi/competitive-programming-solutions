// Codeforces ####A - Sage's Birthday
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

int N;
vi A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    cout << (N-1)/2 << endl;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A.PB(x);
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        if ((N-1)/2 + i < N) {
            cout << A[(N-1)/2+i] << " ";
        }
        else {
            break;
        }
        if (i < (N-1)/2) {
            cout << A[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
