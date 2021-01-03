// DMOPC '19 Contest 6 P4 - Grade 12 Math
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, Q, A[NMAX], freq[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> Q;

    freq[500000] = N;
    for (int i = 0; i < N; i++) {
        A[i] = 500000;
    }

    while (Q--) {
        int query; cin >> query;
        if (query == 1) { // increase
            int x; cin >> x;
            freq[A[x]]--;
            A[x]++;
            freq[A[x]]++;
        }
        else if (query == 2) { // decrease
            int x; cin >> x;
            freq[A[x]]--;
            A[x]--;
            freq[A[x]]++;
        }
        else { // query

        }
    }


    return 0;
}
