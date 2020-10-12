// Codeforces ####A. Avoiding Zero
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
#define NMAX 55
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N, sum, s;
vi A, B, ans;
bool taken[NMAX];

void printAns() {
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        A.clear();
        sum = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int x; cin >> x; A.PB(x);
            sum += x;
        }
        if (!sum) {
            cout << "NO" << endl;
        }
        else {
            for (int start = 0; start < N; start++) {
                B = A;
                ans.clear();

                s = B[start];
                ans.PB(B[start]);
                B.erase(B.begin()+start);

                bool foundAns = true;
                for (int i = 1; i < N; i++) {
                    bool f = false;
                    for (int j = 0; j < sz(B); j++) {
                        if (s + B[j]) {
                            f = true;
                            s += B[j];
                            ans.PB(B[j]);
                            //cout << i << ": ";
                            //printAns();
                            B.erase(B.begin()+j);
                            break;
                        }
                    }
                    if (!f) {
                        foundAns = false;
                        break;
                    }
                }
                if (foundAns) {
                    cout << "YES\n";
                    printAns();
                    break;
                }
            }
        }
    }

    return 0;
}
