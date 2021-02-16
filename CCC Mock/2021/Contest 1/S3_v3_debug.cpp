// Mock CCC '21 S3 - Lexicographically Smallest Permutation Subsequence
#include <bits/stdc++.h>
using namespace std;
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

int N, K, A[NMAX], last[NMAX];
vi ans;
bool inans[NMAX];
bool asserttest[NMAX];
int fraudcount;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

void printA() {
    cout << "PRINTING A" << endl;
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    srand((unsigned) time(0));
    cout << "hi" << endl;

    for (int t = 0; t < 10000; t++) {
        //cin >> N >> K;
        cout << "t = " << t << endl;
        N = rand() % 10000 + 1;
        K = rand() % N + 1;
        memset(last, -1, sizeof(last));
        memset(asserttest, 0, sizeof(asserttest));
        memset(inans, 0, sizeof(inans));
        ans.clear();
        for (int i = 0; i < N; i++) {
            //cin >> A[i];
            A[i] = rand() % K + 1;
            last[A[i]] = i;
        }
        bool flag = true;
        for (int i = 1; i <= K && flag; i++) {
            if (last[i] == -1) flag = false;
        }
        if (!flag) continue;
        printA();
        for (int i = 0; i < N; i++) {
            if (!inans[A[i]]) {
                inans[A[i]] = true;
                while (sz(ans) && ans.back() > A[i] && i < last[ans.back()]) {
                    inans[ans.back()] = false;
                    ans.pop_back();
                }
                ans.PB(A[i]);
            }
        }
        //assert(sz(ans) == K);
        if (sz(ans) != K) {
            cout << "FRAUD: SIZE OF ANS IS NOT K" << endl;
            fraudcount++;
        }
        for (int i = 0; i < sz(ans); i++) {
            //if (asserttest[ans[i]]) assert(false);
            if (asserttest[ans[i]]) {
                cout << "CAUGHT: " << ans[i] << " is repeated" << endl;
                fraudcount++;
            }
            asserttest[ans[i]] = true;
        }
        for (int i = 0; i < sz(ans); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl << endl;
    }
    cout << "FRAUDCOUNT " << fraudcount << endl;


    return 0;
}
