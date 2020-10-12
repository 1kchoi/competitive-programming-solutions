// Now I am become Death, the destroyer of worlds.
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
#define KMAX 22
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K, ans;
int S[NMAX];
int dp[NMAX][KMAX][3];
bool discovered[NMAX][KMAX][3];

int beats(int num) {
    return (num+1)%3;
}

int loses(int num) {
    return (num+2)%3;
}

int best3(int a, int b, int c) {
    return max(a,max(b,c));
}

int solve(int n, int k, int item) {
    if (!discovered[n][k][item]) {
        discovered[n][k][item] = 1;
        if (n == 0) {
            dp[n][k][item] = 0;
        }
        else {
            if (k == 0) {
                dp[n][k][item] = solve(n-1,k,item) + (item == S[n-1]);
            }
            else {
                int item2 = (item+1)%3;
                int item3 = (item+2)%3;
                dp[n][k][item] = best3(solve(n-1,k,item), solve(n-1,k-1,item2), solve(n-1,k-1,item3)) + (item == S[n-1]);
            }
        }
    }
    return dp[n][k][item];
}

//*
void printDP() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << setw(10) << "(";
            for (int a = 0; a < 3; a++) {
                cout << dp[i][j][a];
                if (a < 2) cout << ",";
            }
            cout << ")";
        }
        cout << endl;
    }
}
//*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'H') {
            S[i] = 0;
        }
        else if (c == 'P') {
            S[i] = 1;
        }
        else {
            S[i] = 2;
        }
    }

    for (int i = 0; i < 3; i++) {
        discovered[0][0][i] = true;
    }

    for (int i = 0; i < 3; i++) {
        ans = max(ans, solve(N,K,i));
    }

    //printDP();

    cout << ans << endl;

    return 0;
}
