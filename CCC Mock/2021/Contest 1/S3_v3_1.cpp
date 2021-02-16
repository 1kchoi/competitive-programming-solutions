// Mock CCC '21 S3 - Lexicographically Smallest Permutation Subsequence
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
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

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        last[A[i]] = i;
    }
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
    assert(sz(ans) == K);
    for (int i = 0; i < sz(ans); i++) {
        assert(!asserttest[ans[i]]);
        asserttest[ans[i]] = true;
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;


    return 0;
}
