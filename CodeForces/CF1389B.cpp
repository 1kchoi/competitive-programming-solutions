// Codeforces 1389B - Array Walk
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

int T, N, K, Z, A[NMAX], PS[NMAX], S[NMAX], ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        ans = 0;
        memset(A, 0, sizeof(A));
        memset(PS, 0, sizeof(PS));
        memset(S, 0, sizeof(S));
        cin >> N >> K >> Z;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            PS[i] = A[i];
            if (i > 0) {
                PS[i] += PS[i-1];
            }
            if (i <= K) {
                S[K-i] = i/2;
            }
        }

        /*
        for (int i = 0; i < N; i++) {
            cout << setw(3) << i << " ";
        }
        cout << endl;
        for (int i = 0; i < N; i++) {
            cout << setw(3) << A[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < N; i++) {
            cout << setw(3) << PS[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < N; i++) {
            cout << setw(3) << S[i] << " ";
        }
        cout << endl;
        */

        for (int i = 1; i <= K; i++) {
            int score;
            if (S[i-1] > Z) {
                score = PS[K-2*Z] + Z*(A[i] + A[i-1]);
                //cout << "hit" << endl;
            }
            else {
                score = PS[i] + S[i]*A[i] + S[i-1]*A[i-1];
            }
            //cout << i << " " << score << endl;
            ans = max(ans, score);
        }
        cout << ans << endl;
    }

    return 0;
}
