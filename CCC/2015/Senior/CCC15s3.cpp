// CCC '15 S3 - Gates
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

int G, P, A[NMAX], ans;

bool check(int X) {
    vi planes(A, A+X);
    sort(planes.begin(), planes.end());
    for (int i = 0; i < X; i++) {
        if (planes[i] < i+1) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> G >> P;
    for (int i = 0; i < P; i++) {
        cin >> A[i];
    }

    ans = -1;
    int L = 0, R = P;
    while (L <= R) {
        int M = L+(R-L)/2;
        if (check(M)) {
            ans = M;
            L = M+1;
        }
        else {
            R = M-1;
        }
    }
    cout << ans << endl;


    return 0;
}
