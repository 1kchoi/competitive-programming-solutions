// DMOPC '20 Contest 2 P5 - Majority Subarrays
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, A[NMAX], ans, freq[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        memset(freq, 0, sizeof(freq));
        for (int j = i; j <= N; j++) {
            freq[A[j]]++;
            for (int k = 1; k <= N; k++) {
                if (freq[k] > (j - i + 1) / 2) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
