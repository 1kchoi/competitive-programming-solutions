// CCC '12 S3 - Absolutely Acidic
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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A[1003];
vi B, C, D;
int best, dif;

bool sortFunc(int x, int y) {
    return A[x] > A[y];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A[x]++;
    }
    for (int i = 0; i < 1003; i++) {
        B.PB(i);
    }
    sort(B.begin(), B.end(), sortFunc);

    bool FLAG = false;
    C.PB(B[0]);
    for (int i = 1; i < 1003; i++) {
        if (A[B[i-1]] == A[B[i]]) {
            if (FLAG) {
                if (!A[B[i]]) {
                    break;
                }
                D.PB(B[i]);
            }
            else {
                C.PB(B[i]);
            }
        }
        else {
            if (FLAG) {
                break;
            }
            else {
                FLAG = true;
                D.PB(B[i]);
            }
        }
    }

    sort(C.rbegin(), C.rend());
    sort(D.rbegin(), D.rend());

    cout << "C:";
    for (int i = 0; i < sz(C); i++) {
        cout << " " << C[i];
    }
    cout << endl;
    cout << "D:";
    for (int i = 0; i < sz(D); i++) {
        cout << " " << D[i];
    }
    cout << endl;

    if (sz(C) > 1) {
        cout << abs(C[0] - C.back()) << endl;
    }
    else {
        cout << max(abs(C[0] - D[0]), abs(C[0] - D.back())) << endl;
    }


    return 0;
}
