// Wesley's Anger Contest 6 Problem 3 - Difference Sorting
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
#define NMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N, A[NMAX], ans;
vi B, bcount;
map<ll, ll> M;


void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B.PB(A[i]);
    }
    sort(all(B));
    bcount.PB(1);
    for (int i = 1; i < N; i++) {
        if (B[i] == B[i - 1]) {
            bcount.PB(bcount[i - 1] + 1);
        }
        else {
            bcount.PB(1);
        }
    }

    int start = 0, j = 0;
    for (int i = 0; i < N; i++) {
        M[A[i]]++;
        while (M[B[j]] >= bcount[j]) {
            j++;
            if (j >= N) break;
        }
        if (j > i) {
            for (++start; start < j; start++) {
                if (start >= N) break;
                ans = max(ans, B[start] - B[start - 1]);
            }
        }
    }
    cout << ans << endl;



    return 0;
}
