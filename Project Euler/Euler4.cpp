// Problem 4 - Largest palindrome product
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

int ans;

int rev(int x) {
    int a = 0;
    while (x) {
        a *= 10;
        a += (x % 10);
        x /= 10;
    }
    return a;
}

bool isPalindrome(int x) {
    return x == rev(x);
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            if (isPalindrome(i * j)) {
                ans = max(ans, i * j);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
