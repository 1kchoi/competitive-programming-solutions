// Codeforces ####A - NAME
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 12
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A[NMAX], ans;
vi solution;

int check(int mask) {
    vi lines;
    int currentsum = 0;
    for (int i = 0; i < N; i++) {
        currentsum += A[i];
        if (mask & (1 << i)) {
            lines.PB(currentsum);
            currentsum = 0;
        }
    }
    if (currentsum) lines.PB(currentsum);
    bool rising = 0;
    for (int i = 1; i < sz(lines); i++) {
        if (lines[i] < lines[i - 1]) {
            if (rising) return -1;
        }
        if (lines[i] > lines[i - 1]) {
            rising = 1;
        }
    }
    if (sz(lines) > ans) solution = lines;
    return sz(lines);
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < (1 << N); i++) {
        int test = check(i);
        ans = max(ans, test);
        cout << bitset<10>(i) << " " << test << endl;
        for (int x : solution) {
            cout << x << " ";
        }
        cout << endl;
        cout << ans << endl << endl;
    }

    cout << ans << endl;


    return 0;
}
