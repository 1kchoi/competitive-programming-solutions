// CCC '19 S3 - Arithmetic Square
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N, A[3][3], infinity = (ll)(1e10+5);

void fillObvious() {
    for (int i = 0; i < 3; i++) {
        ll count = 0;
        for (int j = 0; j < 3; j++) {
            count += (A[i][j] <= -infinity);
        }
        if (count != 1) continue;
        if (A[i][0] <= -infinity) {
            A[i][0] = 2 * A[i][1] - A[i][2];
        }
        else if (A[i][1] <= -infinity) {
            A[i][1] = (A[i][0] + A[i][2]) / 2;
        }
        else {
            A[i][2] = 2 * A[i][1] - A[i][0];
        }
        N++;
        fillObvious();
    }
    for (int i = 0; i < 3; i++) {
        ll count = 0;
        for (int j = 0; j < 3; j++) {
            count += (A[j][i] <= -infinity);
        }
        if (count != 1) continue;
        if (A[0][i] <= -infinity) {
            A[0][i] = 2 * A[1][i] - A[2][i];
        }
        else if (A[1][i] <= -infinity) {
            A[1][i] = (A[0][i] + A[2][i]) / 2;
        }
        else {
            A[2][i] = 2 * A[1][i] - A[0][i];
        }
        N++;
        fillObvious();
    }
}

void printSquare() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

bool testAns() {
    fillObvious();
    if (N == 9) {
        printSquare();
        return true;
    }
    return false;
}

bool checkAns() {
    for (int i = 0; i < 3; i++) {
        if (A[i][0] + A[i][2] != 2 * A[i][1]) return false;
        if (A[0][i] + A[2][i] != 2 * A[1][i]) return false;
    }
    return true;
}

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(A, -INF, sizeof(A));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string s; cin >> s;
            if (s[0] == 'X') continue;
            N++;
            A[i][j] = (ll)(stoi(s));
        }
    }
    if (testAns()) return 0;


    if (N == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                A[i][j] = 0;
            }
        }
        N = 9;
    }
    if (testAns()) return 0;


    if (N == 1) {
        ll num = -infinity;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                num = max(num, A[i][j]);
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                A[i][j] = num;
            }
        }
        N = 9;
    }
    if (testAns()) return 0;


    if (N == 2) {
        fillObvious();
        int foundi = -1, foundj = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (A[i][j] > -infinity) {
                    A[i][(j + 1) % 3] = A[i][j];
                    N++;
                    foundi = i, foundj = j;
                    break;
                }
            }
        }
        assert(foundi > -1 && foundj > -1);
        if (!checkAns()) {
            cout << "heyy" << endl;
            N--;
            A[foundi][foundj] = -2 * infinity;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << i << " " << j << endl;
                    if (A[j][i] > -infinity) {
                        A[(j + 1) % 3][i] = A[j][i];
                        N++;
                        break;
                    }
                }
            }
        }
    }
    if (testAns()) return 0;

    if (N == 3) {
        if ((A[0][0] > -infinity && A[1][1] > -infinity && A[2][2] > -infinity) ||
        (A[0][2] > -infinity && A[1][1] > -infinity && A[2][0] > -infinity)) {
            A[0][1] = A[1][1];
            N++;
        }
        else if (A[1][1] > -infinity) {
            if (A[1][0] > -infinity) {
                A[0][0] = A[1][0];
            }
            else {
                A[0][0] = A[0][1];
            }
            N++;
        }
        else {
            A[1][1] = infinity;
            if (A[0][1] > -infinity) {
                A[1][1] = min(A[1][1], A[0][1]);
            }
            if (A[2][1] > -infinity) {
                A[1][1] = min(A[1][1], A[2][1]);
            }
            if (A[1][0] > -infinity) {
                A[1][1] = min(A[1][1], A[1][0]);
            }
            if (A[1][2] > -infinity) {
                A[1][1] = min(A[1][1], A[1][2]);
            }
            assert(A[1][1] != infinity);
             // fix this to prevent passing 1B
            N++;
        }
    }
    if (testAns()) return 0;

    if (N == 5) {
        N++;
        bool r[3], c[3];
        memset(r, 1, sizeof(r));
        memset(c, 1, sizeof(c));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (A[i][j] <= -infinity) {
                    r[i] = 0;
                    c[j] = 0;
                }
            }
        }
        if (r[0]) {
            if (c[0]) {
                A[1][1] = A[0][1] + A[1][0] - A[0][0];
            }
            if (c[1]) {
                A[1][0] = A[1][1] + A[0][0] - A[0][1];
            }
            if (c[2]) {
                A[1][1] = A[0][1] + A[1][2] - A[0][2];
            }
        }
        if (r[1]) {
            if (c[0]) {
                A[0][1] = A[0][0] + A[1][1] - A[1][0];
            }
            if (c[1]) {
                A[0][0] = A[1][0] + A[0][1] - A[1][1];
            }
            if (c[2]) {
                A[0][1] = A[0][2] + A[1][1] - A[1][2];
            }
        }
        if (r[2]) {
            if (c[0]) {
                A[1][1] = A[1][0] + A[2][1] - A[2][0];
            }
            if (c[1]) {
                A[1][0] = A[1][1] + A[2][0] - A[2][1];
            }
            if (c[2]) {
                A[1][1] = A[1][2] + A[2][1] - A[2][2];
            }
        }
    }
    if (testAns()) return 0;

    return 0;
}
