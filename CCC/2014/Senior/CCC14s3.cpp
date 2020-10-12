// CCC '14 S3 - The Geneva Confection
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
#define INF 0x7f7f7f7f
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N;
vi A, B;
bool ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        A.clear(); B.clear();
        ans = true;

        cin >> N;
        for (int i = 0; i < N; i++) {
            int x; cin >> x; A.PB(x);
        }

        for (int i = 1; i <= N && ans; i++) {
            if (A.empty()) {
                if (B.back() != i) {
                    ans = false;
                    break;
                }
            }
            while (B.empty() || B.back() != i) {
                if (A.empty()) {
                    if (B.back() != i) {
                        ans = false;
                        break;
                    }
                }
                else {
                    B.PB(A.back());
                    A.pop_back();
                }
            }
            B.pop_back();
        }

        if (ans) {
            cout << "Y\n";
        }
        else cout << "N\n";
    }

    return 0;
}
