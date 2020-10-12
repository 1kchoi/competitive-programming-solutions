// Codeforces 375B. Maximum Submatrix 2
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(5e3+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, R[NMAX][NMAX], ans;
bool A[NMAX][NMAX];
vi freqsort;
vi psum;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            A[i][j] = (s.at(j) == '1');
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = M-1; j >= 0; j--) {
            if (A[i][j]) {
                R[i][j] = (j==M-1) ? 1 : R[i][j+1]+1;
            }
        }
    }

    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
    */

    for (int j = 0; j < M; j++) {
        freqsort.clear();
        freqsort.assign(N+10, 0);
        psum.clear();
        psum.assign(N+10, 0);
        for (int i = 0; i < N; i++) {
            freqsort[R[i][j]]++;
        }
        for (int i = N+9; i >= 0; i--) {
            psum[i] = freqsort[i];
            if (i < N+9) {
                psum[i] += psum[i+1];
            }
        }
        for (int i = 1; i < N+10; i++) {
            ans = max(ans, psum[i]*i);
        }
    }

    cout << ans << endl;

    return 0;
}
