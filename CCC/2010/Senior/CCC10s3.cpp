// CCC '10 S3 - Firehose
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

/*
NOTE:
above is the template that i copy and paste into every new competitive
programming problem file. if you don't use C++ (yet), you can safely ignore it
*/

// VARIABLES
int H, K, houses[1005], ans;

bool check(int x) {
    for (int start = 0; start < H; start++) {
        int a = 1; // counts the # of firehoses placed if the first one is placed at "start"
        int chain = start; // leftmost position of our current firehose

        for (int i = 0; i < H && a <= K; i++) { // cutting the loop if "a" exceeds "K"
            int pos = (start + i) % H; // adjusting "i" for circular structure with modulo (%)

            if (pos < chain) { // if your chain passed over position 1,000,000
                if (houses[pos] + 1000000 > houses[chain] + 2 * x) {
                    chain = pos;
                    a++;
                }
            }
            else {
                if (houses[pos] > houses[chain] + 2 * x) {
                    chain = pos;
                    a++;
                }
            }
        }

        if (a <= K) return true;
    }
    return false;
}

/*
NOTE:
I highly switching over to C++ for competitive programming, partially because
it is a faster language than both Java and Python, but mainly because of the
wealth of materials you have access to. Most of the books out there are written
in C++, so at least being fluent in READING C++ will greatly benefit you. I'll
probably make a video about this later. :)
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    // INPUT
    cin >> H;
    for (int i = 0; i < H; i++) {
        cin >> houses[i];
    }
    cin >> K;
    sort(houses, houses + H); // sort input into increasing order

    // BINARY SEARCH
    int lo = 0, hi = 999999;
    while (lo <= hi) {
        int med = lo + (hi - lo) / 2; // prevents integer overflow
        if (check(med)) {
            ans = med;
            hi = med - 1;
        }
        else {
            lo = med + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
