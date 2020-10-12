// CCC '16 S4 - Combining Riceballs
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 405
#define INF 0x7f7f7f7f
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, psum[NMAX], ans;
bool dp[NMAX][NMAX], discovered[NMAX][NMAX];

int getSum(int i, int j) {
    if (i == 0) {
        return psum[j];
    }
    return psum[j] - psum[i-1];
}

bool solve (int i, int j) {
    if (!discovered[i][j]) {
        discovered[i][j] = true;
        if (i >= j) {
            dp[i][j] = true;
        }
        else {
            int a = i, b = j;
            while (a < b) {
                if (getSum(i,a) == getSum(b,j)) {
                    bool x = solve(i,a), y = solve(a+1,b-1), z = solve(b,j);
                    if (x && y && z) {
                        dp[i][j] = true;
                        break;
                    }
                    else {
                        a++; b--;
                    }
                }
                else if (getSum(i,a) > getSum(b,j)) {
                    b--;
                }
                else { // sum(i,a) < sum(b,j);
                    a++;
                }
            }
        }
    }
    return dp[i][j];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> psum[i];
        if (i) {
            psum[i] += psum[i-1];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (solve(i,j)) {
                ans = max(ans, getSum(i,j));
            }
        }
    }

    cout << ans << endl;

    return 0;
}
